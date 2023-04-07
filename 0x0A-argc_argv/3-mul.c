#include <stdio.h>

/**
 * main - Entry point
 *
 * @argc: argument counts
 *
 * @argv: vector of arguments
 *
 * Return: 0 always on success
 */

int main(int argc, char *argv[])
{
	int i;
	unsigned int result;

	if ((argc - 1) != 2)
	{
		printf("Error\n");
		return (1);
	}

	i = 1;
	result = 1;
	while (i < argc)
	{
		result *= atoi(argv[i]);
		i++;
	}
	printf("%u\n", result);

	return (0);
}
