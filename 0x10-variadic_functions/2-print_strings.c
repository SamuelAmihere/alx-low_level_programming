#include <stdio.h>
#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print_strings - prints strings
 *
 * @separator: string to be printed between the strings
 * @n: the number of strings passed to the function
 *
 * Return: nothing
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char str[n];
	va_list l;

	va_start(l, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(l, int);
		if (!str)
			printf("(nil)");
		else
			printf("%s", n);
		if (separator && i < (n - 1))
			printf("%s", separator);
	}
	_putchar('\n');

	va_end(l);

}
