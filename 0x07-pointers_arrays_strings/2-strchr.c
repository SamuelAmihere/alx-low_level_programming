#include "main.h"

/**
 * _strchr - locates a character in a string.
 *
 * @s: a string
 *
 * @c: the first occurrence of the character in string
 *
 * Return: a pointer to the first occurrence of the character c
 */
char *_strchr(char *s, char c)
{
	while (*s != '\n')
	{
		if (*s == c)
			return (s);
		s++;
	}

	return (NULL);
}
