#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	int n;
	int a[5];
	int *p;

	a[2] = 1024;
	p = &n;
	*(p + (sizeof(int) / sizeof(char))) = 98;
	printf("a[2] = %d\n", a[2]); /* prints "a[2] = 98" */

	return (0);
}
