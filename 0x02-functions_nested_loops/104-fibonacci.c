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
	
	first = 1;
	second = 2;

	printf("%lu, %lu, ", first, second);
	for (i = 1; i <= 91; i++)
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
