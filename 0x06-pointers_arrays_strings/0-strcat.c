#include "main.h"

/**
 * _strcat - concatenates two strings.
 *
 * @dest: destination string
 *
 * @src: source string
 *
 * Return: cantenated string
 */

char *_strcat(char *dest, char *src)
{
	char *tmp;

	tmp = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (tmp);

}
