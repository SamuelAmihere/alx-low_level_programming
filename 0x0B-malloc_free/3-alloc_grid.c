#include "main.h"
#include <stdlib.h>



/**
 * **alloc_grid - function to create a pointer to
 * a 2 dimensional array of integers.
 *
 * @width: int type
 * @height: int type
 *
 * Return: grid of 0s
 */

int **alloc_grid(int width, int height)
{
	int i, j, **ptr;

	if (width <= 0 || height <= 0)
	{
		return  (NULL);
	}

	ptr = malloc(sizeof(int *) * height);

	if (ptr != NULL)
	{
		for (i = 0; i < height; i++)
		{
		ptr[i] = malloc(sizeof(int) * width);
			if (ptr[i] == NULL)
			{
				for (j = 0; j < i;  j++)
					free(ptr[j]);
				free(ptr);
				return (NULL);
			}
			for (j = 0; j < width;j++)
				ptr[i][j] = 0;

		}
	}
	else
		return (ptr);
}
