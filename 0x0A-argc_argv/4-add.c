#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
	int i, result, num;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	i = 1;
	result = 0;
	while (i < argc)
	{
		if (!isdigit(*argv[i]))
		{
			printf("Error\n");
			return (1);
		}
		else
		{
			num = atoi(argv[i]);
			if (num <= 0)
			{
				printf("Error\n");
				return (1);
			}
			result += atoi(argv[i]);
		i++;
	}

	printf("%d\n", result);

	return (0);
}


