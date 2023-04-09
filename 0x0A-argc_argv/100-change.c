#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int neg_or_nondigit(char *ptr);

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
	int i = 0, j, result, num;
	int denominations[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num = neg_or_nondigit(argv[1]);
	if (num == -2)
		return (1);

	for (; i < 5; i++)
	{
		if (num == -1)
			return (0);
		if (num == 0)
		{
			printf("%d\n", result);
			return (0);
		}
		if (denominations[i] <= num)
		{
			result += num / denominations[i];
			num = abs(num - (denominations[i] * (num /
			denominations[i])));
		}
		for (j = 0; j < 5; j++)
		{
			if (num == denominations[j])
			{
				result += 1;
				num = 0;
			}
		}
	}
	printf("%d\n", result);
	return (0);
}

/**
 * neg_or_nondigit - checks for negative and nondigits
 * @ptr: pointer to string to test
 * Return: 0 for negative test, 1 for digit test
 */
int neg_or_nondigit(char *ptr)
{
	int i = 0, j = 0;

	i = atoi((ptr));
	while (*ptr != '\0')
	{
		if (*ptr == '-')
		{
			printf("0\n");
			i = -1;
		}
		if (!isdigit(*ptr))
			i = -2;
		j++;
		ptr++;
	}
	i = atoi((ptr));
	return (i);
}
