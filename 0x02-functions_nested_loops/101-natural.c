#include <stdio.h>
/**
 *main - Entry point
 *
 * Return: Always 0 on Success
 */
int main(void)
{
	int i;
	int sum;

	for (i = 0; i < 1024; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}
	printf("%d", sum);
	putchar('\n');
	return (0);
}
