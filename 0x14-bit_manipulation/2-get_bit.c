#include "main.h"

/**
 * get_bit - Finds the value of a bit at a given index.
 *
 * @n: a positive number
 *
 * @index: the index
 *
 * Returns: the value of the bit at index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int i = 0;
	int *ptr = get_binary(n);

	if (index >= U_BITS(sizeof(unsigned long int)))
		return (-1);
	return ((n >> index) & 1);
}
