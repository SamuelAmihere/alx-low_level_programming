#include "main.h"

/**
 * rot13 - encodes a string using rot13.
 *
 * @str: string to encode
 *
 * Return: encoded string
 */

char *rot13(char *str)
{
	int i, j;

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 13; j++)
		{
			if ((str[i] >= 'a' && str[i] < 'z') ||
					(str[i] >= 'A' && str[i] < 'Z'))
			{
				str[i]++;
			} else if (str[i] == 'z')
			{
				str[i] = 'a';
			} else if (str[i] == 'Z')
			{
				str[i] = 'A';
			}
		}
	}

	return (str);
}
