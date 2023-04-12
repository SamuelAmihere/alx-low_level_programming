#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all arguments of the program
 *
 * @ac: int type
 * @av: pointer to array
 *
 * Return: 0 on Success
 */

char *argstostr(int ac, char **av)
{
	int i, size, offset;
	char *arg, *result;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	size = 0;
	for (i = 0; i < ac; i++)
	{
		arg = av[i];
		while (*arg != '\0')
		{
			size++;
			arg++;
		}
		size++;
	}
	size++;
	result = (char *) malloc(size);
	if (result == NULL)
		return (NULL);
	offset = 0;
	for (i = 0; i < ac; i++)
	{
		arg = av[i];
		while (*arg != '\0')
		{
			result[offset] = *arg;
			offset++;
			arg++;
		}
		result[offset] = '\n';
		offset++;
	}
	result[offset] = '\0';
	return (result);
}
