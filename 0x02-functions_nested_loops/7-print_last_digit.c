#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number
 *
 * @n: a number whose last digit to be printed
 *
 * Return: last didt of n
 */
int print_last_digit(int n)
{
	int r;

	r = n % 10;
	_putchar(r + '0');
	return (r);
}
