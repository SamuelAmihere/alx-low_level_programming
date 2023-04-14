#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array using
 * amlloc
 *
 * @nmemb: number of arrays
 * @size: size of nmemb
 *
 * Return: pointer to allocated memory
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	int i;
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr != NULL)
	{
		for (i = 0; i < nmemb * size; i++)
			ptr[i] = 0
		return (ptr);
	}
	else
		return (NULL);


}
