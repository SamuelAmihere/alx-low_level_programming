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
	char *ptr = s;

	while (*ptr != '\0')
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	if (*ptr == '\0')
		return (ptr);

	return ('\0');
}
