#include <stdio.h>
#include "main.h"

/**
 * print_alphabet - Produces alphabets in lowercase
 *
 * Return: void
 */
void print_alphabet(void)
{
	char x;

	for (x = 'a'; x <= 'z'; x++)
	{
		_putchar(x);
	}
	_putchar('\n');
}
