#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "main.h"

int _strlen(char *s);

/**
 * create_file - create_file
 *
 * @filename: File's name
 *
 * @text_content: A NULL terminated string
 *
 * Return: 1 on Success, -1 on Failure or filename is NULL
 */
int create_file(const char *filename, char *text_content)
{
	int fdisc, len, bytes_w;

	fdisc = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (!filename || fdisc == -1)
		return (-1);

	if (text_content)
	{
		len = _strlen(text_content);
		bytes_w = write(fdisc, text_content, len);

		if (bytes_w != len)
		{
			close(fdisc);
			return (-1);
		}
	}

	close(fdisc);
	return (1);
}



/**
 * _strlen - returns the length of a string.
 *
 * @s: input string.
 *
 * Return: length of a string.
 */

int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;

	return (count);
}
