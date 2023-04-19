#include <stdio.h>

#include "function_pointers.h"

/**
 * int_index - integer searcher
 *
 * @array: array of elements to search
 * @size: number of elements in the array
 * @cmp: pointer to the function
 *
 * Return: index of the first element if matches,
 * -1 if no element matches or size less or equal 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if  (size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (0);
		else
			return (i);
	}

	return (-1);
}
