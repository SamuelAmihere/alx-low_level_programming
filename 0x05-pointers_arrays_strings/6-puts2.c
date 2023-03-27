#include "main.h"

/**
 * puts2 - prints every other character of a string
 *
 * @str: char array
 *
 * Return - void
 */

void puts2(char *str)
{
	int i, j;

	i = 0;
	while (str[i] != '\0')
		i++;

	for (j = 0; j < i - 1; j++)
	{
		if (str[j + 1] == '\0')
			break;
		else if (j == 0)
			_putchar(str[j]);
		else if ((j + 1) % 2 == 0)
			continue;
		else
			_putchar(str[j]);
	}
}
