#include "main.h"
int get_len(char *s);
/**
 * _print_rev_recursion - prints a string in reverse.
 *
 * @s: a string to reverse
 *
 * Return: nothing
 */
void _print_rev_recursion(char *s)
{
	int len = get_len(s);

	if (*s != '\0')
	{
		_putchar(s + len);
		len--;

	}
	else
		_putchar('\n');
}

/**
 * get_len - get the length of a string
 * @s: a string to find length
 * Return: length of a string
 */
int get_len(char *s)
{
	int i = 0;

	if (*s != '\0')
	{
		i++;
		get_len(s + 1);
	}
	else
		return (i);
}
