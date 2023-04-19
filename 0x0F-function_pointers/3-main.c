#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * main - Entry point
 *
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *op;
	int a, b, result;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	op = argv[2];
	if (!(get_op_func(op)))
	{
		printf("Error\n");
		exit(99);
	}

	b = atoi(argv[3]);
	if (b == 0 && (*op == '/' || *op == '%'))
	{
		printf("Error\n");
		exit(100);
	}

	a = atoi(argv[1]);
	result = (get_op_func(op))(a, b);

	printf("%d\n", result);

	return (0);
}
