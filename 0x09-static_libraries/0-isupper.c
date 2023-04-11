#include "main.h"

#include <stdio.h>
#include <ctype.h>

/**
 * _isupper - checks is a character is upper
 * @c: a character to be checked for uppercase
 * Return: Always 1 Success, 0 otherwise
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
