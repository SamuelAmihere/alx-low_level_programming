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
