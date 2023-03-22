#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 on Success
 */
int main(void)
{
	int i;
	int first = 1;
	int second = 2;
	int next_num;
	int sum;

	printf("%d, %d, ", first, second);
	sum += second;
	for (i = 3; i <= 50; i++)
	{
		next_num = first + second;
		if (next_num <= 4000000)
		{
			first = second;
			second = next_num;
			if (first % 2 == 0)
				sum += first;
			if (second % 2 == 0)
				sum += second;
		}
	}
	printf("%d", sum);
	putchar('\n');
	return (0);
}
