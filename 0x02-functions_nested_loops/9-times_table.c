#include "main.h"

/**
 * times_table - prints time table
 *
 * Return: void
 */
void times_table(void)
{
	int i;
	int j;
	int ans;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			ans = i * j;
			if (ans < 10 && j > 0)
			{
				putchar(' ');
				putchar(ans + '0');
			}
			else if (ans < 10)
				putchar(ans + '0');
			else
			{
				putchar((ans / 10) + '0');
				putchar((ans % 10) + '0');
			}
			if (j != 9)
			{
				putchar(',');
				putchar(' ');
			}
				putchar('\n');
	}
}
