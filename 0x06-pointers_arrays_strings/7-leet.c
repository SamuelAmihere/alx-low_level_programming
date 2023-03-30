#include "main.h"

/**
 * leet - encodes a string into 1337.
 *
 * @str: a string to encode
 *
 * Return:encoded string
 */

char *leet(char *str)
{
	char leet_char[5] = {'4', '3', '0', '7', '1'};
	char lowercase[5] = {'a', 'e', 'o', 't', 'l'};
	char uppercase[5] = {'A', 'E', 'O', 'T', 'L'};
	int i, j;

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (str[i] == lowercase[j] || str[i] == uppercase[j])
			{
				str[i] = leet_char[j];
				break;
			}
		}
	}

	return (str);
}
