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
	int x;

	for (x = 0; x <= 7; x++)
	{
		for (i = 0; i <= 8; i++)
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
						putchar(x + '0';)
						putchar(i + '0');
						putchar(j + '0');
					}
					if (i != 8)
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
