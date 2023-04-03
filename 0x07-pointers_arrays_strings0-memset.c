#include "main.h"

/**
 * _memset - fills memory with a constant byte.
 *
 * @s: memory area being pointed to
 * @b: constant byte
 * @n: number of bytes of memory area
 * Return: a pointer to memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i;

	for (i = 0; i < n, ++i)
	{
		*(s + i) = b;
	}

	return (*s);
}
