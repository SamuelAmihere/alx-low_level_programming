#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates strings.
 *
 * @s1: first string
 * @s2: second string
 * @n: number of bytes of s2
 *
 * Return: pointer on success, NULL on failure
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	int i, n2 = n, count = 0, count2 = 0;
	char *ptr;

	if (s1 != NULL)
	{
		while (*(s1 + count) != '\0')
			count++;
	}
	if (s2 != NULL)
	{
		while (count2 >= 0)
		{
			if (*(s2 + count2) == '\0' && count2 == n2)
				break;
			else if  (count2 == n2)
				break;
			count2++;
		}
	}

	ptr = malloc(sizeof(s1[0]) * (count + count2) + 1);

	if (ptr != NULL)
	{
		for (i = 0; i < (count + count2); j++)
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
