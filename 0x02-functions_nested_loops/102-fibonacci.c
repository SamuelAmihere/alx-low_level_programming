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

	printf("%d, %d, ", first, second);
	for (i = 3; i <= 50; i++)
	{
		next_num = first + second;
		if (next_num != 20365011074)
			printf("%d, ", next_num);
		else
			printf("%d", next_num);
		first = second;
		second = next_num;
	}
	putchar('\n');
	return (0);
}
