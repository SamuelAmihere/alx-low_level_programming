#include "main.h"

/**
 * _strncat - concatenates two strings.
 *
 * @dest: destination string
 *
 * @src: source string
 *
 * @n: number of bytes
 *
 * Return: cantenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	char *tmp;
	int i;

	tmp = dest;
	i = 0;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0' && i < n)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}

	*dest = '\0';

	return (tmp);

}
