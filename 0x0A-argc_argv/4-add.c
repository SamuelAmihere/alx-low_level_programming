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
	int result;
	int num;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	i = 1;
	result = 0;
	while (i < argc)
	{
		num = atoi(argv[i]);
		if (num > 0 || *argv[i] == '0')
			result += num;
		else
		{
			printf("Error\n");
			return (1);
		}

		i++;
	}

	printf("%d\n", result);

	return (0);
}
