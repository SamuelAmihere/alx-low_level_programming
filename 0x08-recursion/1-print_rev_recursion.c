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
		s += 1;
		_print_rev_recursion(s);

	}
	else
	{
		s -= 1;
		print(s);
	}
}

/**
 * print - reverse a string
 * @s: a string to reverse
 * Return: nothing
 */
void print(char *s)
{

	if (*s != '\0')
	{
		if (*s != '\n')
		{
			_putchar(*s);
			s = s - 1;
			print(s);
		}
		else
			_putchar('\n');
	}
	else
		_putchar('\n');
}
