#include "main.h"

/**
 * print_number - prints an integer.
 *
 * @n: a number to print
 *
 * Return: nothing
 */

void print_number(int n)
{
	int divisor = 1;
	unsigned int un;

	if (n < 0)
	{
		_putchar('-');
		un = -n;
	}
	else
		un = n;
	while (un / divisor >= 10)
	{
		divisor *= 10;
	}
	while (divisor != 0)
	{
		_putchar((un / divisor) % 10 + '0');
		divisor /= 10;
	}
}
