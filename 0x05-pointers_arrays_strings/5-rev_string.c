#include "main.h"

/**
 * rev_string - Reverses a string
 *
 * @s: char pointer
 *
 * Return - void
 */

void rev_string(char *s)
{
	int i;
	char tmp[_strlen(s)];

	for (i = _strlen(s) - 1; i >= 0; i--)
	{
		tmp[i - _strlen(s) - 1] = s[i];
	}
	*s = &tmp;
	_putchar('\n');
}

/**
 * _strlen - determines the length of a string.
 *
 * @s: char pointer
 *
 * Return: interger
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

