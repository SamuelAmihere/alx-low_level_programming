#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers.
 *
 * @a: array of integers
 *
 * @n:  number of elements of the array
 *
 * Return: nothing.
 */

void reverse_array(int *a, int n)
{
	int *ptr1 = a;
	int *ptr2 = a + n - 1;
	int tmp;

	while (ptr1 < ptr2)
	{
		tmp = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = tmp;
		ptr1++;
		ptr2--;
	}
}
