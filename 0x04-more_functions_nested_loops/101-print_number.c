#include <stdio.h>
#include "main.h"
/**
 * print_number - prints an integer.
 *
 * @n: integer to print
 *
 * Return: void
 */
void print_number(int n)
{
	unsigned int i, j, divisor;

	divisor = 1;

	if (n < 0)
	{
		_putchar('-');
		n = n * -1;
	}
	i = n;
	while (i >= 10)
	{
		divisor = divisor * 10;
		i = i / 10;
	}
	j = divisor;
	while (j >= 1)
	{
		divisor = divisor / 10;
		_putchar((n / j) % 10 + '0');
		j = j / 10;
	}
}
