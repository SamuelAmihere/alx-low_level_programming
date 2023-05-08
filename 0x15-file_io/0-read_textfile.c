#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - reads a text file and prints it
 *
 * @filename: File's name
 *
 * @letters: the number of letters to read and print
 *
 * Return: numbers read, 0 if file not opened or filename is
 * NULL or write fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *fptr;
	char *s;
	int fdisc;
	int bytes_w, bytes_r;

	s = malloc(sizeof(char) * letters);
	if (s == -1 || !filename)
	{
		return (0);
	}

	fdisc = open(filename, O_RDONLY);
	if (fdisc == -1)
		return (0);

	bytes_r = read(fdisc, s, letters);

	bytes_w = write(STDOUT_FILENO, s, bytes_r);
	if (bytes_w == -1)
		return (0);

	close(fdisc);
	free(s);

	return (bytes_w);
}
