/*
 * File: 103-keygen.c
 * Auth: Gedeon Obae Gekonge
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 6

char generatePasswordChar(char *codex, int value);
int calculateTmpValue(char *str, int xorValue);

/**
 * main - Generates and prints passwords for the crackme5 executable.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char password[PASSWORD_LENGTH + 1];
	char *codex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	int len = strlen(argv[1]);
	int i, tmp;

	if (len == 0) {
		printf("No input provided.\n");
		return 1;
	}

	tmp = (len ^ 59) & 63;
	password[0] = generatePasswordChar(codex, tmp);

	tmp = calculateTmpValue(argv[1], 79);
	password[1] = generatePasswordChar(codex, tmp);

	tmp = calculateTmpValue(argv[1], 85);
	password[2] = generatePasswordChar(codex, tmp);

	tmp = argv[1][0];
	for (i = 0; i < len; i++) {
		if (argv[1][i] > tmp)
			tmp = argv[1][i];
	}
	srand(tmp ^ 14);
	password[3] = generatePasswordChar(codex, rand() & 63);

	tmp = calculateTmpValue(argv[1], 239);
	password[4] = generatePasswordChar(codex, tmp);

	for (i = 0; i < argv[1][0]; i++)
		tmp = rand();
	password[5] = generatePasswordChar(codex, tmp ^ 229);

	password[PASSWORD_LENGTH] = '\0';
	printf("%s\n", password);
	return 0;
}

/**
 * generatePasswordChar - Generates a password character based on the given codex and value.
 * @codex: The codex containing the characters to choose from.
 * @value: The value used to index the codex.
 *
 * Return: The generated password character.
 */
char generatePasswordChar(char *codex, int value)
{
	return codex[value];
}

/**
 * calculateTmpValue - Calculates the temporary value based on the given string and XOR value.
 * @str: The input string.
 * @xorValue: The value to XOR with the calculated tmp value.
 *
 * Return: The calculated tmp value.
 */
int calculateTmpValue(char *str, int xorValue)
{
	int len = strlen(str);
	int tmp = 0;
	int i;

	for (i = 0; i < len; i++)
		tmp += str[i];

	return (tmp ^ xorValue) & 63;
}

