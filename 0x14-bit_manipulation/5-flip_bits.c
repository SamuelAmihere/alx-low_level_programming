#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count;
	unsigned long int diff;

	count = 0;
	diff = n ^ m;

	while (diff)
	{
		if ((diff & 1ul) == 1)
			count++;
		diff >>= 1;
	}

	return (count);
}
