#include "main.h"

/**
 * set_bit - sets the value of a bit
 *
 * @n: pointer to the number to modify
 *
 * @index: index of the bit to set value
 *
 * Return: 1 on success, -1 on failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index - 1 >= U_BITS(sizeof(unsigned long int)))
		return (-1);

	*n |= 1ul << index;

	return (1);
}
