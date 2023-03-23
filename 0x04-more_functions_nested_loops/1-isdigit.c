#include <stdio.h>
#include <ctype.h>

/**
 * _isdigit - checks is a character is lower
 *
 * @c: a character to be checked for lowercase
 *
 * Return: Always 1 Success, 0 otherwise
 */
int _isdigit(int c)
{
	if (isdigit(c))
		return (1);
	else
		return (0);
}
