#include "main.h"

/**
 * _strspn - gets the length of a prefix substring.
 * @s: string
 *
 * @accept: substring
 *
 * Return: the number of bytes
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	char *ptr = accept;

	while (*s != '\0')
	{
		while (*ptr != '\0')
		{
			if (*s == *ptr)
			{
				count++;
				break;
			}
			ptr++;
		}
		if (*ptr == '\0')
			break;
		s++;
	}
	return (count);
}
