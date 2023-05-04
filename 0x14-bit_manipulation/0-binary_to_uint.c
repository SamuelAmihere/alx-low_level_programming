#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 *
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: converted number, 0 if otherwise
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int dec = 0;

	if (b)
	{
		i = 0;
		while (b[i] != '\0')
		{
			if (b[i] == '0' || b[i] == '1')
				dec = (b[i] - '0') + dec * 2;
			else
				return (0);
			i++;
		}
	}
	return (dec);
}
