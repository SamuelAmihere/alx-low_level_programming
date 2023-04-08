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
	int i, j, result, num;
	char *ptr;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		ptr = argv[i];
		j = 0;
		while (ptr[j] != '\0')
		{
			if (!isdigit(ptr[j]))
			{
				printf("Error\n");

				return (1);
			}
			j++;
		}
		num = atoi(ptr);
		result += num;
	}

	printf("%d\n", result);

	return (0);
}


