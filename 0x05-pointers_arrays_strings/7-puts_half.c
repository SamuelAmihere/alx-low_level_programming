#include "main.h"

/**
 * puts_half - prints half of a string
 *
 * @str: char array
 *
 * Return - void
 */

void puts_half(char *str)
{
	int i, j, k;

	i = 0;
	while (str[i] != '\0')
		i++;

	j = i / 2;
	for (k = 0; k <= j; k++)
		_putchar(str[k]);

	_putchar('\n');
}
