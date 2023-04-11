#include "main.h"
int len(char *s);
int pal_helper(int i, char *s)

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
	int i = 1;

	return (pal_helper(i, s));
}

/**
 * pal_helper - finds length of string
 *
 * @i: integer
 * @s: string
 * Return: length of s
 */

int pal_helper(int i, char *s)
{
	if (*s)
	{
		int strlen = len(s);

		if (*s != s[strlen - i])
			return (0);
		return (pal_helper(i + 1, s + 1));
	}
	i = 1;
	return (i);
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
