#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to a newly allocated memory
 * for concatenated s1 and s2, NULL on
 * failure
 */

char *str_concat(char *s1, char *s2)
{
	int j, count = 0, count2 = 0;
	char *ptr;

	if (s1 == NULL)
		*s1 = '\0';
	if (s2 == NULL)
		*s2 = '\0';

	while (*(s1 + count) != '\0')
		count++;

	while (count2 >= 0)
	{
		if (*(s2 + count2) == '\0')
			break;
		count2++;
	}

	ptr = malloc(sizeof(s1[0]) * (count + count2) + 1);

	if (ptr != NULL)
	{
		for (j = 0; j < (count + count2); j++)
		{
			if (j < count)
				ptr[j] = s1[j];
			else
				ptr[j] = s2[j - count];
		}
		return (ptr);
	}
	else
		return (NULL);
}
