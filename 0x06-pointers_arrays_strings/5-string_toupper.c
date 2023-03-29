#include "main.h"

/**
 * string_toupper -  changes all lowercase letters of a string to uppercase.
 *
 * @s: the string to change
 *
 * Return: string in uppercase
 */

char *string_toupper(char *s)
{
	char *ptr = s;

	while (*ptr != '\0')
	{
		if (*ptr >= 'a' && *ptr <= 'z')
			*ptr -= ('a' - 'A');
		ptr++;
	}

	return (s);
}
