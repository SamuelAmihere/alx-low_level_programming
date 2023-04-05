#include "main.h"
void print(char *s);
/**
 * _print_rev_recursion - prints a string in reverse.
 *
 * @s: a string to reverse
 *
 * Return: nothing
 */
void _print_rev_recursion(char *s)
{
	if (*s != '\0')
	{
		s = s + 1;
		_print_rev_recursion(s);

	}
	else
	{
		print(s);
		_putchar(*s);
	}
}

/**
 * print - reverse a string
 * @s: a string to reverse
 * Return: nothing
 */
void print(char *s)
{
	if (*s != '\n' || *s != '\0')
	{
		_putchar(*s);
		s = s - 1;
		print(s);
	}
}