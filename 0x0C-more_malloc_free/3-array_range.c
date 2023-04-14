#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers.
 *
 * @min: first array
 * @max: second array
 *
 * Return: pointer to created array
 */

int *array_range(int min, int max)
{
	int i, count;
	int *ptr;

	if (min > max)
		return (NULL);

	while (max >= min)
	{
		max -= 1;
		count++;
	}

	ptr = malloc(count * sizeof(int));

	if (ptr != NULL)
	{
		i = 0;
		while (min <= max)
		{
			ptr[i] = min;
			i++;
			min++;
		}
		return (ptr);
	}
	else
		return (NULL);

}
