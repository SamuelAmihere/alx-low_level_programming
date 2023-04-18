#include <stdlib.h>
#include <stdio.h>
#include "dog.h"

int _strlen(char *s);
char *_strcpy(char *dest, char *src);

/**
 * new_dog - creates new dog
 *
 * @name: name of dog
 * @age: age of dog
 * @owner: dog's owner
 *
 * Return: newly dog
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	d = malloc(sizeof(dog_t));

	if (d == NULL)
		return (NULL);

	d->name = malloc(_strlen(name) + 1);
	d->owner = malloc(_strlen(owner) + 1);

	if (d->name == NULL)
	{
		free(d->name);
		return (NULL);
	}
	if (d->owner == NULL)
	{
		free(d->owner);
		free(d);
		return (NULL);
	}

	_strcpy(d->name, name);
	_strcpy(d->owner, owner);

	d->age = age;

	return (d);
}


/**
 * _strlen - returns the length of a string.
 *
 * @s: input string.
 *
 * Return: length of a string.
 */

int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;

	return (count);
}


/**
 * _strcpy - copies the string pointed to by src,
 *
 * including the terminating null byte, to the
 * buffer pointed to by dest.
 * @dest: destination.
 * @src: source.
 *
 * Return: the pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}

	return (dest);
}
