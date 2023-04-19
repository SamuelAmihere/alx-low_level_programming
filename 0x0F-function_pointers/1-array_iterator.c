#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - function executor
 *
 * @array: array of elements
 * @size: size of the array
 * @action: pointer to the function you need to use
 *
 * Return: Nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (!array || !action)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
