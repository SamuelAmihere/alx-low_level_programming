#include "main.h"

/**
 * clear_bit - sets to 0 to clear bit
 *
 * @n: pointer to the number to change
 *
 * @index: index of bit to clear
 *
 * Return: 1 on success, -1 on failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= U_BITS(sizeof(unsigned long int)) + 1)
		return (-1);

	*n = ~(1ul << index) & *n;

	return (1);
}
