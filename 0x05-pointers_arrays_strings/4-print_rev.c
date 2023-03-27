#include "main.h"

/**
 * print_rev - prints a string, in reverse, followed by a new line.
 *
 * @s: string array pointer
 *
 * Return void
 */

void print_rev(char *s)
{
	int i;

	for (i = _strlen(s); i > 0; i--)
		_putchar('\n');

	_putchar('\n');
}
