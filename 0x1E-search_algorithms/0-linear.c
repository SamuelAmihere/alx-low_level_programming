#include "search_algos.h"

/**
 * linear_search - Linear search algorithm in array
 * @array: a pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located, -1 if NULL or not found
 */
int linear_search(int *array, size_t size, int value)
{
	int i = 0;


	if (!array)
		return (-1);

	for (i = 0; i < (int)size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
