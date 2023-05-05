
#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 *
 * @n: An integer
 *
 * Return: nothing
 */
void print_binary(unsigned long int n)
{
	int total_bits = U_BITS(sizeof(unsigned long int));
	int count = 0;
	unsigned long int new;

	while (total_bits >= 0)
	{
		new = n >> total_bits;
		if (count)
			_putchar('0');
		else if (new & 1)
		{
			_putchar('1');
			count += 1;
		}
		total_bits--;
	}

	if (!count)
		_putchar('0');
}
