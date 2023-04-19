#include <stdlib.h>

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
	char *func;
	int num;

	if (argc == 0)
		return (0);

	func = (*get_op_func(argv[1]))(atoi(argv[1]), atoi(argv[3]));

	if (func)
	{
		printf("%d\n", func);
	}

	return (0);
}
