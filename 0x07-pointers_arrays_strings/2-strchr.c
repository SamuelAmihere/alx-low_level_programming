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
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}

	if (s == NULL)
		return (NULL);
}
