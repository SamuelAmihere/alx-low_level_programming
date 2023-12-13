#include "search_algos.h"
/**
* linear_search - searches value in an array of integers
*
* @array: pointer to the first element
*
* @size: number of elements
*
* @value: value to search
*
* Return: index or -1 if value is not present in
* array or if array is NULL
*/
int linear_search(int *array, size_t size, int value)
{
	unsigned int i = 0;


	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);

		if (array[i] == value)
			return (i);
	}
	return (-1);
}
