#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * error - print an error message and exit with a given error code
 *
 * @file: file being processed
 * @code: exit code
 *
 * Return: nothing
 */
void error(char __attribute__((unused))*file, int code)
{
	if (code == 98)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
				file);
	}
	else if (code == 99)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	else if (code == 97)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");

	exit(code);
}

/**
 * open_file - open a file
 *
 * @filename: file name
 * @flags: flag for file permissions
 * @mode: file mode
 *
 * Return: file descriptor
 */
int open_file(char *filename, int flags, mode_t mode)
{
	int fdesc;

	fdesc = open(filename, flags, mode);
	if (fdesc < 0)
	{
		error(filename, 98);
	}
	return (fdesc);
}

/**
 * copy_file - read from one file and write to another
 *
 * @src: source file
 * @dest: destination file
 *
 * Return: nothing
 */
void copy_file(int src, int dest)
{
	char buffer[BUFFER_SIZE];
	int bytes_r, bytes_w;

	bytes_r = read(src, buffer, BUFFER_SIZE);

	while (bytes_r > 0)
	{
		bytes_w = write(dest, buffer, bytes_r);
		if (bytes_w < 0 || dest < 0)
			error(dest, 99);
	}

	if (bytes_r < 0)
		error(src, 98);
}


/**
 * close_file - close a file
 *
 * @fdesc: file descriptor
 *
 * Return: nothing
 */
void close_file(int fdesc)
{
	int fclose;

	fclose = close(fdesc);
	if (fclose == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdesc);
		exit(100);
	}
}


/**
 * main - copies a file's contents to another file
 *
 * @argc: number of parameters
 *
 * @argv: pointer to arguments
 *
 * Return: o on Success
 * exit code 97 (incorrect argc)
 * exit code 98 (src file does not exist)
 * exit code 99 (dest file does not exist)
 * exit code 100 (both files connot be closed)
 */
int main(int argc, char *argv[])
{
	int src, dest;

	if (argc != 3)
		error(argv[1], 97);

	src = open_file(argv[1], O_RDONLY, 0);
	dest = open_file(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

	copy_file(src, dest);

	close_file(src);
	close_file(dest);

	return (0);
}
