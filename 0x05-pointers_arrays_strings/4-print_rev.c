#include "main.h"

/**
 * print_rev - prints a string, in reverse, followed by a new line.
 *
 * @s: pointerb to string array
 *
 * Return void
 */

void print_rev(char *s)
{
	int i;

	for (i = _strlen(*s); i > 0; i--)
		_putchar('\n');

	_putchar('\n');
}

/**
 * _strlen - determines the length of a string.
 *
 * @s: char pointer
 *
 * Return: interger
 *
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	return (len);

}
