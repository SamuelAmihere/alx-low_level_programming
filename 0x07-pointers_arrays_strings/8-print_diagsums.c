#include "main.h"

/**
 * print_diagsums - prints the sum of the two
 * diagonals of a square matrix of integers.
 *
 * @a: integer array
 *
 * @size: dimensions
 *
 * Return: nothing
 */
void print_diagsums(int *a, int size)
{
	int i, j;
	unsigned int l = 0, r = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i == j)
				l += a[i][j];
			else if ((i + j) == size)
				r = a[i][j];
		}

	}
	printf("%d, %d\n", l, r);
}
