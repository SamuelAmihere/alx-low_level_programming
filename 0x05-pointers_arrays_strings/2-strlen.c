#include "main.h"

/**
 * _strlen - returns the length of a string.
 *
 * @s: pointerb to string array
 *
 * Return: length of array
 */

int _strlen(char *s)
{
	int len;

	len = 0;
	while (*s != '0')
	{
		len++;
		str++;
	}

	return (len);
}
