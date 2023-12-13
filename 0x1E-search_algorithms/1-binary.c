#include "search_algos.h"

/**
* binary_search - searches for a value from sorted arrays
*
* @array: a pointer to the first element
* @size: a number of elements
* @value: the value to search
*
* Return: index, -1 if value not in array or array is NULL
*/
int binary_search(int *array, size_t size, int value)
{
	int l = 0, h = size - 1, m = 0, i;

	if (!array || size == 0)
		return (-1);

	while (l <= h)
	{
		printf("Searching in array: ");

		for (i = l; i < h; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);
		m = l + ((h - l) / 2);

		if (value == array[m])
			return (m);
		else if (value < array[m])
			h = m - 1;
		else if (value > array[m])
			l = m + 1;
		else if (l == h)
			return (-1);
	}
	return (-1);
}
