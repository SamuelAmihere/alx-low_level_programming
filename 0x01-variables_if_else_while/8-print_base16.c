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

	for (i = 0; i <= 0xF; i++)
	{
		if (i <= 9)
			putchar(i + '0');
		else
			putchar(tolower(i + '7'));
	}

	putchar('\n');
	return (0);
}
