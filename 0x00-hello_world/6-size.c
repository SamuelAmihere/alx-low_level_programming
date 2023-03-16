#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char myChar;
	int myInt;
	long int myLongInt;
	long long int myLongLongInt;
	float myFloat;

	printf("Size of a char: %d byte(s)\n", myChar);
	printf("Size of an int: %d byte(s)\n", myInt);
	printf("Size of a long int: %d byte(s)\n", myLongInt);
	printf("Size of a long long int: %d byte(s)\n", myLongLongInt);
	printf("Size of a float: %d byte(s)\n", myFloat);

	return (0);
}
