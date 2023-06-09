#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - prints the sum of the two diagnonals
 *
 * @a: pointer to array
 *
 * @size: dimensions
 *
 * Return: nothing
 */
void print_diagsums(int *a, int size)
{
	int i, left_d, right_d;

	left_d = 0;
	right_d = 0;
	for (i = 0; i < size; i++)
	{
		left_d += a[i * size + i];
	}
	for (i = size - 1; i >= 0; i--)
		right_d += a[i * size + (size - 1 - i)];

	printf("%d, %d\n", left_d, right_d);
}
