#include "main.h"
#include <stdlib.h>
/**
 * create_array - creates an array of chars,
 * and initializes it with a specific char.
 *
 * @size: size of array
 * @c: character to fill array
 *
 * Return: pointer to array on success,
 * NULL if size is 0 or faiure
 */

char *create_array(unsigned int size, char c)
{
	char *ptr;

	if (size == 0)
		return (NULL);
	ptr = malloc(sizeof(c) * size);
	if (ptr)
		return (ptr);
	else
		return (NULL);

}
