#include "main.h"
int len(char *s);
int pal_helper(int l, int i, char *s);

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
	int l = len(s);

	return (pal_helper(l, 0, s));
}

/**
 * pal_helper - compare string to its reverse
 *
 * @l: length of s
 * @i: iterator
 * @s: string
 * Return: 1 on Success
 */

int pal_helper(int l, int i, char *s)
{
	if (*(s + i) != *(s + l - 1))
		return (0);
	if (i >= l)
		return (1);
	return (pal_helper(l - 1, i + 1, s));
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
