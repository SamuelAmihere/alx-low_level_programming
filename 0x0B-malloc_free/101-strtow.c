#include "main.h"
#include <stdlib.h>

int get_num_words(char *str);
int str_length(char *str);

/**
 * strtow - splits a string into words
 * @str: string to be split
 *
 * Return: pointer to the array of split words
 */
char **strtow(char *str)
{
	char **split;
	int i, j = 0, temp = 0, size = 0, words = get_num_words(str);

	if (words == 0)
	return (NULL);

	split = malloc(sizeof(char *) * (words + 1));
	if (split == NULL)
		return (NULL);

	for (i = 0; i < str_length(str) && j < words; i++)
	{
		if (str[i] != ' ')
			size++;
		else if (size > 0)
		{
			split[j] = malloc(sizeof(char) * (size + 1));
			if (split[j] != NULL)
			{
				for (temp = 0; temp < size; temp++)
					split[j][temp] = str[(i - size)
						+ temp];
				split[j][temp] = '\0';
				size = 0;
				j++;
			} else
			{
				while (j-- > 0)
					free(split[j]);
				free(split);
				return (NULL);
			}
		}

	}
	if (size > 0)
	{
		split[j] = malloc(sizeof(char) * (size + 1));
		if (split[j] != NULL)
		{
			for (temp = 0; temp < size; temp++)
				split[j][temp] = str[(i - size) + temp];
			split[j][temp] = '\0';
			j++;
		} else
		{
			while (j-- > 0)
				free(split[j]);
			free(split);
			return (NULL);
		}
	}
	split[j] = NULL;
	return (split);
}

/**
 * get_num_words - gets the number of words in a string
 * @str: string to be used
 *
 * Return: number of words
 */
int get_num_words(char *str)
{
	int i, num_words = 0;
	char prev_char = ' ';

	for (i = 0; i < str_length(str); i++)
	{
		if (str[i] == ' ' && prev_char != ' ')
			um_words++;
		prev_char = str[i];
	}

	if (prev_char != ' ')
		num_words++;
	return (num_words);
}

/**
 * str_length - returns the length of a string
 * @str: string to be counted
 *
 * Return: length of the string
 */
int str_length(char *str)
{
	int len = 0;

	if (str != NULL)
	{
		while (str[len])
			len++;
	}
	return (len);
}
