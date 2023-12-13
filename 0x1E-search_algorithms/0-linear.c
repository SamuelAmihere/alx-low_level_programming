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
	size_t l = 0;

	if (!array || size == 0)
		return (-1);

	while (l < size)
	{
		printf("Value checked array[%d] = [%d]\n", (int)l, array[l]);
		if (array[l] == value)
			return (array[l]);
		l += 1;
	}
	return (-1);
}
