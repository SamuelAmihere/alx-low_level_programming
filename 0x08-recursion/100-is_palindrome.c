#include "main.h"
int len(char *s);
int pal_helper(int i, char *s);

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
	int i = len(s);

	return (pal_helper(i, s));
}

/**
 * pal_helper - compare string to its reverse
 *
 * @i: length of s
 * @s: string
 * Return: 1 on Success
 */

int pal_helper(int i, char *s)
{
	int strlen = len(s);

	if (*s != *(s + i))
		return (0);
	else if (*s == 0)
		return (1);
	return (pal_helper(i - 2, s + 1));
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
