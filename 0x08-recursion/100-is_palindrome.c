#include "main.h"
int len(char *s);
/**
 * is_palindrome - returns 1 if a string
 * is a palindrome and 0 if not.
 *
 * @s: some string
 *
 * Return: 1 or 0
 */

int is_palindrome(char *s)
{
	int strlen = len(s);

	if (*s != '\0')
	{
		if (*s != *(s + strlen - 1))
		{
			return (1);
		}
		else
			return (1 + is_palindrome(s + 1));
	}
	else
		return (0);
}

/**
 * len - returns the length of a string.
 * @s: a string to find its length
 * Return: length of string s
 */

int len(char *s)
{
	if (*s != '\0')
	{
		return (1 + len(s + 1));
	}
	else
		return (0);
}
