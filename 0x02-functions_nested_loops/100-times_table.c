#include <stdio.h>
#include "main.h"

/**
 * print_times_table - prints time table
 *
 * @n: number of times to print
 *
 * Return: void
 */
void print_times_table(int n)
{
	int i;
	int j;
	int ans;

	if ( n > 15 || n < 0)
	{
		return;
	}

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			ans = i * j;
			if (ans < 10 && j != 0)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar(' ');
				_putchar(ans + '0');
			}
			else if (ans < 100 && ans >= 10)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar((ans / 10) + '0');
				_putchar((ans % 10) + '0');
			}
			else if (ans == 0)
			{
				_putchar(ans + '0');
			}
			else if (ans >= 100)
			{
				_putchar(',');
				_putchar(' ');
				_putchar((ans / 100) + '0');
				_putchar(((ans / 10) % 10) + '0');
				_putchar((ans % 10) + '0');
			}
		}
		_putchar('\n');
	}
}
