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
 * append_text_to_file - appends text
 *
 * @filename: File's name
 *
 * @text_content: A NULL terminated string
 *
 * Return: 1 on Success, -1 on Failure or filename is NULL
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fdisc, len, bytes_a;

	fdisc = open(filename, O_WEONLY | O_APPEND);

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
