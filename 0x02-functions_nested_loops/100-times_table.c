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

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			ans = i * j;
			if ( j != 0)
			{
				_putchar(',');
				_puttchar(' ');

			}
			if (ans < 10 && j != 0)
			{
				_puttchar(' ');
				_puttchar(' ');
				_puttchar((ans % 10) + '0');
			}
			else if (j != 0 && ans > 100)
			{
				_puttchar((ans / 100) + '0');
				_puttchar((ans / 10) % 10 + '0');
				_puttchar((ans % 10) + '0');
			}
			else if (ans < 100 && ans >= 10)
			{
				_puttchar(' ');
				_puttchar((ans / 10) + '0');
				_puttchar((ans % 10) + '0');
			}
			else 
			{
				_puttchar((ans % 10) + '0');
			}
		}
	}
}
