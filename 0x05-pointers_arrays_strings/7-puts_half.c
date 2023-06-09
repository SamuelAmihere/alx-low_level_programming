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
	int i, j;

	i = 0;
	while (str[i] != '\0')
		i++;

	if (i % 2 == 0)
		j = i / 2;
	else
		j = (i + 1) / 2;
	for (; j < i; j++)
		_putchar(str[j]);

	_putchar('\n');

}
