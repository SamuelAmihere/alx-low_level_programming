#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - allocates memory
 * memory
 *
 * @b: unsigned integer type being allocated
 *
 * Return: a pointer
 */


void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);

	if (ptr != NULL)
		return (ptr);
	else
		exit(98);
}
