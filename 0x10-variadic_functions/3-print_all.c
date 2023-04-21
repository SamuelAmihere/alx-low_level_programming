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
	dtype chars[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};
	int i = 0, j = 0;
	char *sep = "";
	va_list l;

	va_start(l, format);

	while (format[i] != '\0')
	{
		while (j < 4 && chars[j].arg != NULL)
		{
			if (*(chars[j].arg) == format[i])
			{
				printf("%s", sep);
				chars[j].f(l);
				sep = ", ";
				break;
			}
			j++;
		}

		i++;
	}
	printf("\n");

	va_end(l);
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
	printf("%d", va_arg(l, int));
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
	{
		printf("%s", s);
		return;
	}
	printf("%s", s);
}
