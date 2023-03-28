#include "main.h"

/**
 * *_strcpy -  copies the string pointed to by src
 *
 * @dest: destination
 *
 * @src: source
 *
 * Return: char
 */

char *_strcpy(char *dest, char *src)
{
	char *ptr;

	ptr = dest;
	while (*src != '\0')
		*ptr++ = *src++;

	*ptr = '\0';

	return (dest);
}
