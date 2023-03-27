#include "main.h"

/**
 * swap_int - swaps the value 2 integers
 *
 * @a: integer pointer
 *
 * @b: integer pointer
 *
 * Return - void
 */

void swap_int(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
