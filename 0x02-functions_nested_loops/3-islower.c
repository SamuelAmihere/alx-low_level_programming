#include <stdio.h>
#include <ctype.h>

/**
 * _islower - checks is a character is lower
 *
 * @c: a character to be checked for lowercase
 *
 * Return: Always 1 Success, 0 otherwise
 */
int _islower(int c)
{
	if (islower())
		return (1);
	else
		return (0);
}
