#include <stdarg.h>

#include "variadic_functions.h"

/**
 * sum_them_all - calculates sum of numbers
 *
 * @n: number of arguments to sum
 *
 * Return: sum of arguments
 */
int sum_them_all(const unsigned int n, ...)
{
	int sum = 0;
	const unsigned int i;
	va_list l;

	if (n == 0)
		return (0);
	va_start(l, n);

	for (i = 0; i < n; i++)
	{
		sum += va_arg(l, int);
	}

	va_end(l);

	return (sum);
}
