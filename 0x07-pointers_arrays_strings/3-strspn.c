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

	while (*s != '\0')
	{
		while (*accept != '\0')
		{
			if (*s == *accept)
			{
				count++;
				break;
			}
		}
		s++;
	}
	return (count);
}
