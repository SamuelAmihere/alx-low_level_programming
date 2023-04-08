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

int main(int argc, char **argv)
{
	int i, result;

	if (argc <= 1)
	{
		printf("Error\n");
		return (1);
	}

	i = 1;
	result = 1;
	while (i < argc)
	{
		result = result * (int) *argv[i];
		i++;
	}
	printf("%d\n", result);

	return (0);
}
