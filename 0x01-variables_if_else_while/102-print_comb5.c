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

	for (i = 0; i <= 98; i++)
	{
		for (j = 0; j <= 99; j++)
		{
			if (i < j)
			{
				if (j == 0 || j == i)
				{
					continue;
				}
				else
				{
					putchar((i / 10) + '0');
					putchar((i % 10) + '0');
					putchar(' ');
					putchar((j / 10) + '0');
					putchar((j % 10) + '0');
				}
				if (i != 98)
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
