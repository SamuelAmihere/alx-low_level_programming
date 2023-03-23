#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 Success
 */
int main(void)
{
	unsigned long int i, j, z, value, l;

	value = 612852475143;
	l = 0;
	for (z = 1; z <= value / 2; z++)
	{
		i = value / z;
		j = i * z;
		if (value == j)
		{
			l = i;
			value = i;
			z = 1;
		}
	}
	printf("%lu\n", l);

	return (0);
}
