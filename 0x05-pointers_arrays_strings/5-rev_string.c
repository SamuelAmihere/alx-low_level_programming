#include "main.h"

/**
 * rev_string - Reverses a string
 *
 * @s: char pointer
 *
 * Return - void
 */

void rev_string(char *s)
{
	int i, j, k;
	char tmp, *ptr;
	
	k = 0;
	while (s[k] != '\0')
		k++;

	ptr = s;

	for (i = 0; i < k - 1; i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			tmp = *(ptr + i);
			*(ptr + j) = *(ptr + j - 1);
			*(ptr + j - 1) = tmp;
		}
	}

}
