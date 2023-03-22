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

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (n < 15 && n > 0)
			{
				ans = i * j;
				if (ans < 10)
				{
					_putchar(ans + '0');
					_putchar(',');
					_putchar(' ');

				}
				else
				{
					_putchar((ans / 10) + '0');
					_putchar((ans % 10) + '0');
					_putchar(',');
				}
				if (j != n)
					_putchar(' ');
				else
					_putchar('\n');
			}
	
		}

	}
}
