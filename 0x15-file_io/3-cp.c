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
void error(char *file, int code)
{
	if (code == 98)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
				file);
	}
	else if (code == 99)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	else if (code == 97)
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", file);

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

	if (mode == 0)
		fdesc = open(filename, flags);
	else
		fdesc = open(filename, flags, mode);
	if (fdesc == -1)
	{
		error(filename, 98);
	}
	return (fdesc);
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
 * copy_file - read from one file and write to another
 *
 * @sr: source file
 * @dst: destination file
 *
 * Return: nothing
 */
void copy_file(char *sr, char *dst)
{
	char buffer[BUFFER_SIZE];
	int bytes_r, bytes_w, src, dest;

	src = open_file(sr, O_RDONLY, 0);
	if (src == -1)
		error(sr, 98);

	dest = open_file(dst, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (dest == -1)
		error(dst, 99);


	while (bytes_r == BUFFER_SIZE)
	{
		bytes_r = read(src, buffer, BUFFER_SIZE);
		if (bytes_r < 0)
			error(sr, 98);

		bytes_w = write(dest, buffer, bytes_r);
		if (bytes_w < 0)
			error(dst, 99);
	}

	close_file(src);
	close_file(dest);
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
	char *sr, *dst;

	if (argc != 3)
		error("cp", 97);

	sr = argv[1];
	dst = argv[2];

	copy_file(sr, dst);

	return (0);
}
