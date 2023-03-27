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
	int i, j, len;
	char tmp, *ptr;

        len = _strlen(s);
	ptr = s;

	for (i = 0; i < len - 1; i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			tmp = *(ptr + i);
			*(ptr + j) = *(ptr + j - 1);
			*(ptr + j - 1) = tmp;
		}
	}

}

/**
 * _strlen - determines the length of a string.
 *
 * @s: char pointer
 *
 * Return: interger
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

