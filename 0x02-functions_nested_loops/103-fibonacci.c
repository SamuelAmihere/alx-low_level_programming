#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 on Success
 */
int main(void)
{
	int i;
	unsigned long int first, second, next_num, sum;
	first = 1;
	second = 2;
	next_num;
	sum = 0;

	for (i = 1; i <= 33; i++)
	{
		
		if (next_num < 4000000)
		{
			if (first % 2 == 0)
				sum += first;
		}
		next_num = first + second;
		first = second;
		second = next_num;
	}
	printf("%ld", sum);
	putchar('\n');
	return (0);
}
