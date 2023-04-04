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
	int i, left_d = 0, right_d = 0;

	for (i = 0; i < (size * size); i += size + 1)
	{
		left_d += a[i];
	}
	for (i = (size - 1); i < (size * size - 1); i += size - 1)
	{
		right_d += a[i];
	}
	printf("%d, %d\n", left_d, right_d);
}
