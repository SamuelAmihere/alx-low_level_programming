#include <stdio.h>
#include <stdlib.h>

void print_opcodes(int n, int (*add)(int, char **));

/**
 * main - Entry point
 *
 * @argc: The number of arguments provided
 * @argv: Array of arguments
 *
 * Return: 0 on Success
 */
int main(int argc, char **argv)
{
	int bytes, (*func_ptr)(int, char **) = main;

	bytes = atoi(argv[1]);
	if (bytes < 0)
	{
		printf("Error\n");
		exit(1);
	}

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	print_opcodes(bytes, func_ptr);
	printf("\n");

	return (0);


}

/**
 * print_opcodes - Prints the opcodes
 *
 * @n: elements of an array
 *
 * Return: nothing
 */
void print_opcodes(int n, int (*addr)(int, char **))
{
	int i;
	unsigned char code;

	for (i = 0; i < n; i++)
	{
		code = *(unsigned char *)addr;
		printf("%.2x", code);

		if (i != n - 1)
			printf(" ");
		
		i++;	
	}
}
