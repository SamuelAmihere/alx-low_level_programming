#include <stdio.h>
#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal.
 *
 * @n: number of times to draw
 *
 * Return: void
 */
void print_diagonal(int n)
{
	int i;
	int j;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j == i)
			{
				_putchar('\\');
				_putchar('\n');
			}
		}

	}
	_putchar('\n');
}
