#include "main.h"
#include <stdlib.h>
#include <limits.h>

/**
 * _strdup - creates a pointer to a newly allocated
 * space in memory
 *
 * @str: string to create copy of
 *
 * Return: a poiter to duplicate of str,
 * NULL if str is NULL or insufficient memory
 */

char *_strdup(char *str)
{
	char *d;
	int i, j;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		i++;
	}

	d = malloc(sizeof(str[0]) * i);

	if (d != NULL)
	{
		for (j = 0; j < i; j++)
			d[j] = *(str + j);
		return (d);
	}
	else
		return (NULL);

}
