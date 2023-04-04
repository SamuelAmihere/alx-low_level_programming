#include "main.h"

/**
 * print_diagsums - prints the sum of the two
 * diagonals of a square matrix of integers.
 *
 * @a: pointer to array
 *
 * @size: dimensions
 *
 * Return: nothing
 */
void print_diagsums(int *a, int size)
{
	int i, j, left_d = 0, right_d = 0;

	for (i = 0; i < (size * size); i += size + 1)
	{
		left_d += a[i];
	}
	for (j = (size - 1); j < (size * size - 1); j += size - 1)
	{
		right_d += a[j];
	}
	printf("%d, %d\n", left_d, right_d);
}
