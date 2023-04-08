#include <stdio.h>
#include <stdlib.h>

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

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	i = 1;
	result = 0;
	while (i < argc)
	{
		if (atoi(argv[i]) || *argv[i] == 48)
			result += atoi(argv[i]);
		else
		{
			printf("Error\n");
			return (1);
		}
		i++;
	}
	printf("%u\n", result);

	return (0);
}
