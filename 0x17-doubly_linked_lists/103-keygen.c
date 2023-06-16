#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 6

char generatePasswordChar(char *codex, int value);
int calculateTmpValue(char *str, int xorValue);

/**
 * main - Entry point to generates and prints passwords.
 * @argc: Arguments passed to the program.
 * @argv: Array of pointers passed.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char password[PASSWORD_LENGTH + 1];
	char *codex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+"
		"4mjW6fxqZeF3Qa1rPhdKIouk";
	int inputLength = strlen(argv[1]);
	int i, tmpValue;

	if (inputLength == 0)
	{
		printf("No input provided.\n");
		return (1);
	}

	/* Generate password characters based on input */
	tmpValue = (inputLength ^ 59) & 63;
	password[0] = generatePasswordChar(codex, tmpValue);

	tmpValue = calculateTmpValue(argv[1], 79);
	password[1] = generatePasswordChar(codex, tmpValue);

	tmpValue = calculateTmpValue(argv[1], 85);
	password[2] = generatePasswordChar(codex, tmpValue);

	tmpValue = 0;
	for (i = 0; i < inputLength; i++)
	{
		if (argv[1][i] > tmpValue)
			tmpValue = argv[1][i];
	}
	srand(tmpValue ^ 14);
	password[3] = generatePasswordChar(codex, rand() & 63);

	tmpValue = 0;
	for (i = 0; i < inputLength; i++)
		tmpValue += (argv[1][i] * argv[1][i]);
	password[4] = generatePasswordChar(codex, (tmpValue ^ 239) & 63);

	for (i = 0; i < argv[1][0]; i++)
		tmpValue = rand();
	password[5] = generatePasswordChar(codex, (tmpValue ^ 229) & 63);

	password[PASSWORD_LENGTH] = '\0';
	printf("%s\n", password);
	return (0);
}

/**
 * generatePasswordChar - Generates a password character based
 * on the given codex and value.
 * @codex: The codex containing the characters to choose from.
 * @value: The value used to index the codex.
 *
 * Return: The generated password character.
 */
char generatePasswordChar(char *codex, int value)
{
	return (codex[value]);
}

/**
 * calculateTmpValue - Calculates the temporary value based
 * on the given string and XOR value.
 * @str: The input string.
 * @xorValue: The value to XOR with the calculated tmp value.
 *
 * Return: The calculated tmp value.
 */
int calculateTmpValue(char *str, int xorValue)
{
	int inputLength = strlen(str);
	int tmpValue = 0;
	int i;

	for (i = 0; i < inputLength; i++)
		tmpValue += str[i];

	return ((tmpValue ^ xorValue) & 63);
}
