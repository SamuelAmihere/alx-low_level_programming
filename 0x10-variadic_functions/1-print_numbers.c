#include <stdio.h>
#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print_numbers - prints numbers
 *
 * @separator: string to be printed between numbers
 * @n: number of integers passed to the function
 * @...: actual integers passed to the argument
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
			if (i == 0)
				printf("%d%c", va_arg(l, int), *separator);
			else if (i > 0 && i < n - 1)
				printf(" %d%c", va_arg(l, int), *separator);
			else if (i == n - 1)
				printf(" %d", va_arg(l, int));
		}
	}

	va_end(l);

	_putchar('\n');
}
