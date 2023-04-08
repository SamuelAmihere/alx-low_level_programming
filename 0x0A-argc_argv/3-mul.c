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
	int i, result;

	if (argc <= 1)
	{
		printf("Error\n");
		return (1);
	}

	result = (int) argv[1] * (int) argv[2];

	printf("%d\n", result);

	return (0);
}
