#include <stdio.h>
#include "main.h"
/**
 * print_triangle - prints a triangle, followed by a new line.
 *
 * @size: size of triangle
 *
 * Return: void
 */
void print_triangle(int size)
{
	int i;
	int j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (j + i >= size - 1)
				_putchar('#');
			else
				_putchar(' ');
		}
		_putchar('\n');
	}
}
