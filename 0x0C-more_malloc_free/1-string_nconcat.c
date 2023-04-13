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
	int i, l2, n2 = n, count = 0, count2 = 0;
	char *ptr;

	if (s1 != NULL)
	{
		while (*(s1 + count) != '\0')
			count++;
	} 
	else
		*s1 = "";

	if (s2 != NULL)
	{
		while (count2 >= 0)
		{
			if (*(s2 + count2) == '\0' && count2 >= n2)
				break;
			else if  (count2 == n2)
				break;
			count2++;
		}
	} 
	else
		*s2 = "";

	ptr = malloc(sizeof(s1[0]) * (count + count2) + 1);
	*(ptr + count + count2) = '\0';

	if (ptr != NULL)
	{
		for (i = 0; i < (count + count2); i++)
		{
			if (i < count)
				ptr[i] = s1[i];
			else
				ptr[i] = s2[i - count];
		}
		return (ptr);
	}
	else
		return (NULL);


}
