#include "main.h"

/**
 * infinite_add - adds two numbers.
 *
 * @n1: first number to add
 *
 * @n2: second number to add
 *
 * @r:  buffer that the function will use to
 * store the result
 *
 * @size_r: buffer size
 *
 * Return: results
 */
char *infinite_add(char *n1, char *n2,
	       char *r, int size_r)
{
	int carry = 0, i = 0, j = 0, k = 0;
	int a, b, sum, x;
	char tmp;

	/* Calculate the length of both input strings */
	while (n1[i] != '\0')
		i++;
	while (n2[j] != '\0')
		j++;
	/* Check if the result will fit in the output buffer */
	if (i > size_r || j > size_r)
		return (0);
	/* Iterate from the end of the strings and add digits */
	while (i > 0 || j > 0 || carry > 0)
	{
		a = i > 0 ? n1[--i] - '0' : 0;
		b = j > 0 ? n2[--j] - '0' : 0;
		sum = a + b + carry;
		if (k < size_r - 1)
		{
			r[k++] = (sum % 10) + '0';
			carry = sum / 10;
		} else
			/* The result doesn't fit in the output buffer */
			return (0);
	}
	/* Add null terminator and reverse the result */
	r[k] = '\0';
	for (x = 0; x < k / 2; x++)
	{
		tmp = r[x];
		r[x] = r[k - x - 1];
		r[k - x - 1] = tmp;
	}

	return (r);
}
