#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int _strlen(char *s);
void print_err(void);
int is_digit(char *s);

/**
 * main - multiplies two positive numbers
 *
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: o on success
 */

int main(int argc, char **argv)
{
	int l, l1, l2, c, i, num1, num2, *result, j = 0;
	char *str1, *str2;
	_Bool bl;

	str1 = argv[1];
	str2 = argv[2];
	if (!is_digit(str1) || is_digit(str2))
		print_err();

	l1 = _strlen(str1), l2 = _strlen(str2), tl = l1 + l2 + 1;

	result = malloc(tl * sizeof(int));

	if (result == NULL)
		return (1);

	for (i = 0; i <= l1 + l2; i++)
		result[i] = 0;
	for (i = l1 - 1; i >= 0; i--)
	{
		c = 0;
		for (j = l2 - 1; j >= 0; j--)
		{
			num1 = str1[i] - '0';
			num2 = str2[j] - '0';
			c += result[i + j + 1] + (num1 * num2);
			result[i + j] = c % 10;
			c /= 10;
		}
		result[i] += c;
	}
	bl = 1;

	for (i = 0; i < til - 1; i++)
	{
		if (result[i] != 0)
		{
			bl = 0;
		}
		if (!bl)
			_putchar(result[i] + '0');
		}
	if (bl)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);

}

/**
 * _isdigit - checks whether a given input is a digit
 *
 * @c: a parameter to check for digit
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char *s)
{
	int i;
	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _strlen - returns the length of a string.
 *
 * @s: input string.
 *
 *
 * Return: length of a string.
 */
int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;
	return (count);
}

/**
 * print_err - print and exit main due to error
 *
 * Return: nothing
 */
void print_err(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * _putchar - writes the character c to stdout
 *
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
