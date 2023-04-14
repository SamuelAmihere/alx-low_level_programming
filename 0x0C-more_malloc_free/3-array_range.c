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
	int count, m = max;
	int *ptr;

	if (min > max)
		return (NULL);

	count = 0;
	while (m >= min)
	{
		m -= 1;
		count++;
	}

	ptr = malloc(count * sizeof(long int));

	if (ptr != NULL)
	{
		m = 0;
		while (min <= max)
		{
			ptr[m] = min++;
			m++;
		}
		return (ptr);
	}
	else
		return (NULL);

}
