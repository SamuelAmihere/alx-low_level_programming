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
	int up = n / 2 + 1;

	if (n < 0)
		return (-1);
	else
		return (get_sqrt(n, 0, up));
}

/**
 * get_sqrt - find the square root
 * @n: the number to find the square root
 * @a: lower bound of a search
 * @b: upper bound of a search
 * Return: the sqaure root
 */
int get_sqrt(int n, int a, int b)
{
	int m = (a + b) / 2;
	int sq = m * m;

	if (a > b)
		return (-1);
	if (sq < n)
		return (get_sqrt(n, m + 1, b));
	else if (sq == n)
		return (m);
	else
		return (get_sqrt(n, a, m - 1));
}
