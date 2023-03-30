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
	int i;
	int result = 0;
	int sign = 1;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			sign = -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			result = result * 10 - (s[i] - '0');

			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
		}
	}

	return (sign * result);
}
