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
	if (*s != '\0')
	{
		if (*s != s[len[s] - 1])
		{
			return (0);
		}
		else
			is_palindrome(s + 1);
	}
	else
	{
		return (0);
	}

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
		return ((s - (s - 1)) + _strlen_recursion(s + 1));
	}
	else
		return (0);
}
