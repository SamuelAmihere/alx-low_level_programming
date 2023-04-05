#include "main.h"

/**
 * factorial - calculates the factorial of a given number.
 *
 * @n: an integer to determine its factorial
 *
 * Return: the factorial of integer n
 */

int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 1)
		return (1);
	else
		return (n * factorial(n - 1));
}
