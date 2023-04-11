#include "main.h"
int get_sqrt(int n, int a, int b);
/**
 * _sqrt_recursion - find the natural square root of a number.
 *
 * @n: a number to find its root
 *
 * Return: natural square root of a number.
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (get_sqrt(n, 2));
}

/**
 * get_sqrt - find the square root
 *
 * @n: the number to find the square root
 * @a: looper
 *
 * Return: the sqaure root
 */
int get_sqrt(int n, int a)
{
	if (a % (n / a) == 0)
	{
		if (a * (n / a) == n)
			return (a);
		else
			return (-1);
	}
	return (0 + get_sqrt(n, a + 1));
}
