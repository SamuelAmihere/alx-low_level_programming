#include <stdio.h>
#include <ctype.h>

/**
 * _isalpha - checks is a character is lower
 *
 * @c: a character to be checked
 *
 * Return: Always 1 Success, 0 otherwise
 */
int _isalpha(int c)
{
	if (isalpha(c))
		return (1);
	else
		return (0);
}
