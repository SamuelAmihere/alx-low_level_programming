#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes.
 *
 * @s: string
 *
 * @accept: substring to search for bytes
 *
 * Return: a pointer to the byte in s
 */
char *_strpbrk(char *s, char *accept)
{
	char *ptr;

	while (*s != '\0')
	{
		ptr = accept;
		while (*ptr != '\0')
		{
			if (*s == *ptr)
				return (s);
			ptr++;
		}
		s++;
	}
	return (0);
}
