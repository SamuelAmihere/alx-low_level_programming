#include <stdio.h>
#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print_numbers - prints numbers
 *
 * @separator: string to be printed between numbers
 * @n: number of integers passed to the function
 *
 * Return: nothing
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list l;

	va_start(l, n);

	for (i = 0; i < n; i++)
	{
		if (separator)
		{
			printf("%d", va_arg(l, int));
			if (separator && i < (n - 1))
				printf("%s", separator);
		}
	}
	printf("\n");

	va_end(l);
}
