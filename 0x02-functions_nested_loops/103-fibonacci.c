#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 on Success
 */
int main(void)
{
	long i;
	long first = 1;
	long second = 2;
	long next_num;
	long sum = 0;

	sum += second;
	for (i = 3; i <= 50; i++)
	{
		next_num = first + second;
		if (next_num < 4000000)
		{
			if (first % 2 == 0)
				sum += first;
			first = second;
			second = next_num;
		}
	}
	printf("%ld", sum);
	putchar('\n');
	return (0);
}
