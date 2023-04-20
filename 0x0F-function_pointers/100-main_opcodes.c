#include <stdio.h>
#include <stdlib.h>

void print_opcodes(int n, char *add);

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
	int bytes;

        if (argc != 2)
        {
                printf("Error\n");
                exit(1);
        }

	bytes = atoi(argv[1]);
	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	print_opcodes(bytes, (char *)main);
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
void print_opcodes(int n, char *add)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%02xx", add[i] & 0xFF);

		if (i < (n - 1))
			printf(" ");
		
		i++;	
	}
}
