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

	i = -1;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i--;
	}
	_putchar('\n');
}
