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
	int digit1, digit2, carry;
	int sum, i, j, k, lenr;
	char tmp;
	int len1 = 0, len2 = 0;

	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;
	if (len1 >= size_r || len2 >= size_r)
		return (0);
	carry = 0, sum = 0, i = len1 - 1;
	j = len2 - 1, k = 0;
	while (i >= 0 || j >= 0 || carry)
	{
		digit1 = i >= 0 ? n1[i] - '0' : 0;
		digit2 = j >= 0 ? n2[j] - '0' : 0;
		sum = digit1 + digit2 + carry;
		if (sum >= 10)
		{
			carry = 1;
			sum -= 10;
		} else
			carry = 0;
		if (k >= size_r)
			return (0);
		r[k++] = sum + '0';
		i--, j--;
	}
	r[k] = '\0';

	lenr = k;
	for (i = 0; i < lenr / 2; i++)
	{
		tmp = r[i];
		r[i] = r[lenr - i - 1];
		r[lenr - i - 1] = tmp;
	}

	return (r);
}
