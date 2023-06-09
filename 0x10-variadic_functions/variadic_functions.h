#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include<stdarg.h>

void print_char(va_list l);
void print_int(va_list l);
void print_float(va_list l);
void print_string(va_list l);

/**
 * struct ch - multiple choice print
 * @arg: arg Type of print
 * @f: function pointer
 */
typedef struct ch
{
	char *arg;
	void (*f)(va_list);
} chars;

int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
