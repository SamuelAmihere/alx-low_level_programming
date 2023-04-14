#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
/**
 * main - Entry point
 *
 * @argc: argument counts
 *
 * @argv: vector of arguments
 *
 * Return: 0 always on success
 */
int main(int argc, char **argv)
{
	int *result;
	char *num1, *num2;

	num1 = argv[1];
	num2 = argv[2];
	if (argc != 3 || is_digit(num1) == 0 || is_digit(num2) == 0)
	{
		printf("Error\n");
		exit(98);
	}

	result = multiply(num1, num2);

	if (result != NULL)
		print_result(result, str_len(num1) + str_len(num2));
	else
		exit(98);
	free(result);
	return (0);
}

/**
 * multiply - multiplies 2 #'s, prints result, must be 2 #'s
 * @num1: factor # 1 (is the smaller of 2 numbers)
 * @num2: factor # 2 (is the larger of 2 numbers)
 * Return: 0 fail, 1 success
 */
int *multiply(char *num1, char *num2)
{
	int len1 = str_len(num1);
	int len2 = str_len(num2);
	int *result = _calloc(sizeof(int), len1 + len2);
	int i, j, carry, sum;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			sum = (num1[i] - '0') * (num2[j] - '0') +
				result[i + j + 1] + carry;
			result[i + j + 1] = sum % 10;
			carry = sum / 10;
		}
		result[i + j + 1] = carry;
	}
	return (result);
}

/**
 * _calloc - allocates memory for an array using malloc
 * @bytes: bytes of memory needed per requested size
 * @size: size in bytes of each element
 * Return: pointer to the allocated memory
 */
void *_calloc(unsigned int bytes, unsigned int size)
{
	unsigned int i;
	char *ptr;

	if (bytes == 0 || size == 0)
		return (NULL);
	if (size >= UINT_MAX / bytes || bytes >= UINT_MAX / size)
		return (NULL);
	ptr = malloc(size * bytes);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < bytes * size; i++)
		ptr[i] = 0;

	return ((void *)ptr);
}

/**
 * str_len - finds string length
 * @str: input pointer to string
 * Return: length of string
 */
int str_len(char *str)
{
	int len;

	for (len = 0; *str != '\0'; len++)
		len++, str++;

	return (len / 2);
}

/**
 * is_digit - checks for digits
 * @c: input character to check for digit
 * Return: 0 failure, 1 success
 */
int is_digit(char *c)
{
	int i = 1, j = 0;

	while (c[j] != '\0')
	{
		if (c[j] < '0' || c[j] > '9')
		{
			i = 0;
			break;
		}
		j++;
	}

	return (i);
}

/**
 * print_result - prints my array of the hopeful product here
 * @result: pointer to int array with numbers to add
 * @len_r: length of result array
 * Return: void
 */
void print_result(int *result, int len_r)
{
	int i = 0;
	int leading_zeros = 1;

	for (i = 0; i < len_r; i++)
	{
		if (result[i] != 0)
			leading_zeros = 0;
		if (!leading_zeros)
			_putchar(result[i] + '0');
	}
	if (leading_zeros)
		_putchar('0');
	_putchar('\n');
}
