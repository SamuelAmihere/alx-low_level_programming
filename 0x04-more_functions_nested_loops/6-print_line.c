#include <stdio.h>
#include "main.h"

/**
 * print_line - draws a straight line in the terminal.
 *
 * @n: number of times to print
 *
 * Return: void
 */
void print_line(int n)
{
	for (i = 0; i < n; i++)
	{
		_putchar('_');
	}
	_putchar('\n');
}
