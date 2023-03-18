#include <stdio.h>
#include <ctype.h>
/**
 *main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	int j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			if (i < j)
			{
				if (j == 0 || j == i)
				{
					continue;
				}
				else
				{
					putchar(i + '0');
					putchar(j + '0');
				}
				if (i != (10 - 2))
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
