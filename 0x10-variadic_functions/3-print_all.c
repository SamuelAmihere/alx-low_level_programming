#include <stdio.h>
#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print_all - prints anything
 *
 * @format: a list of types of arguments passed to
 * the function
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	chars arr[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"f", print_float},
		{NULL, NULL}
	};
	unsigned int i = 0, j;
	char *sep = "";
	va_list l;

	va_start(l, format);

	while (format && format[i] != '\0')
	{
		j = 0;
		while (arr[j].arg != NULL)
		{
			if (*(arr[j].arg) == format[i])
			{
				printf("%s", sep);
				arr[j].f(l);
				sep = ", ";
				break;
			}
			j++;
		}

		i++;
	}
	va_end(l);
	printf("\n");
}

/**
 * print_char - print char
 *
 * @l: character argument
 *
 * Return: nothing
 */
void print_char(va_list l)
{
	printf("%c", va_arg(l, int));
}

/**
 * print_int - print int
 *
 * @l: int argument
 *
 * Return: nothing
 */
void print_int(va_list l)
{
	printf("%i", va_arg(l, int));
}

/**
 * print_float - print float
 *
 * @l: float argument
 *
 * Return: nothing
 */
void print_float(va_list l)
{
	printf("%f", va_arg(l, double));
}

/**
 * print_string - print strings
 *
 * @l: string argument
 *
 * Return: nothing
 */
void print_string(va_list l)
{
	char *s;

	s = va_arg(l, char *);
	if (s == NULL)
		s = "(nil)";

	printf("%s", s);
}
