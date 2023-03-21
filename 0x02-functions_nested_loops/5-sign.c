#include <stdio.h>
#include <ctype.h>
#include "main.h"

/**
 * print_sign - checks is a character is lower
 *
 * @n: a number whose sign is to be printed
 *
 * Return: Always 1 n is positive, -1 n is negative 0 otherwise
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	_putchar('0');
	return (0);
}
