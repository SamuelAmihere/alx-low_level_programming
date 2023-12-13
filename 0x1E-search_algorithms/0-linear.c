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
	int l = 0;

	if (!array)
		return (-1);

	while (l < (int)size)
	{
		printf("Value checked array[%u] = [%d]\n", l, array[l]);
		if (array[l] == value)
			return (array[l]);
		l += 1;
	}
	return (-1);
}
