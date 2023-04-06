#include "main.h"
int helper_func(char *s1, char *s2);

/**
 * wildcmp - compares two strings and returns
 * 1 if the strings can be considered identical,
 *
 * @s1: first string
 *
 * @s2: second string
 *
 * Return: 0 or 1
 */
int wildcmp(char *s1, char *s2)
{
	return (helper_func(s1, s2));
}

/**
 * helper_func - compares the two strings character by character.
 * @s1: first string
 * @s2: second string
 * Return: 0 or 1
 */
int helper_func(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s1 == *s2)
		return (helper_func(s1 + 1, s2 + 1));
	else if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return (1);
		return (helper_func(s1, s2 + 1) || (*s1 != '\0' &&
				       helper_func(s1 + 1, s2)));
	} else
		return (0);
}
