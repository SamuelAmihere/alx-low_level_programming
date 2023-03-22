#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 on Success
 */
int main(void)
{
	int i;
	unsigned long int first, second, next_num;

	printf("%lu, %lu, ", first, second);
	for (i = 3; i <= 98; i++)
	{
		next_num = first + second;
		if (i != 98)
			printf("%lu, ", next_num);
		else
			printf("%lu", next_num);
		first = second;
		second = next_num;
	}

	putchar('\n');
	return (0);
}
