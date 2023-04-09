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
int main(int argc, char **argv)
{
	int i, j, result, num;
	int denominations[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	num = atoi(argv[1]);
	if (num > 0)
	{
		for (i = 0; i < 5 && num != 0; i++)
		{
			result += num / denominations[i];
			num %= denominations[i];

		}
	}
	printf("%d\n", result);
	return (0);
}
