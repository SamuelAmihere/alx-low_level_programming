#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - calculates sum of numbers
 *
 * @n: number of arguments to sum
 * @...: All arguments passed
 *
 * Return: sum of arguments, 0 if n == 0
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i, sum = 0;
	va_list l;

	va_start(l, n);

	for (i = 0; i < n; i++)
	{
		sum += va_arg(l, int);
	}

	va_end(l);

	return (sum);
}
