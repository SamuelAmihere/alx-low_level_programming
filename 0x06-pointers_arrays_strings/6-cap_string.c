#include "main.h"

/**
 * cap_string -  changes all lowercase letters of a string to uppercase.
 *
 * @s: the string to capitalize each word
 *
 * Return: string in capitalized form
 */

char *cap_string(char *s)
{
	int cap = 1;
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
			       s[i] == ',' || s[i] == ';' || s[i]
			      == '.' || s[i] == '!' || s[i] == '?' ||
			      s[i] == '"' || s[i] == '(' || s[i]
			      == ')' || s[i] == '{' || s[i] == '}')
		{
			cap = 1;
		} else if (cap)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				s[i] -= ('a' - 'A');
			}
			cap = 0;
		}
		i++;
	}

	return (s);
}
