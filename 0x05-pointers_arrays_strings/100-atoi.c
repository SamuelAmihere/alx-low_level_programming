#include "main.h"

/**
 * _atoi - convert a string to an integer
 *
 * @s: string
 *
 * Return: an integer
 */

int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' ||
		      *s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + (*s - '0');
		s++;
	}

	return (sign * num);
}
