#include "main.h"
#include <stdlib.h>

unsigned int get_min(unsigned int int1, unsigned int int2);

/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: pointer to previously allocated memory
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size:new size, in bytes of the new memory block
 *
 * Return: nothing
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		malloc(new_size);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		ptr = malloc(new_size);

	free(ptr);
	ptr = malloc(new_size);

	return (ptr);
}


/**
 * get_min - find minimum
 *
 * @int1: first integer
 * @int2: second integer
 *
 * Return: minimum
 */

unsigned int get_min(unsigned int int1, unsigned int int2)
{
	unsigned int i;
	if (int1 < int2)
		return (int1);
	else
		return (int2);
}
