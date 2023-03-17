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

	do {
		putchar(i + '0');
		putchar(',');
		putchar(' ');
		i++;
	} while (i < 9);

	putchar('9');
	return (0);
}
