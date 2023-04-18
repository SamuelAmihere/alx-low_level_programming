#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - initializes a struct variable
 *
 * @d: dog object
 * @name: name of dog
 * @age: age of dog
 * @owner: dog's owner
 *
 * Return: nothing
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d = malloc(sizeof(struct dog));
	if (d == NULL)
		return (NULL);
	d->name = name;
	d->age = age;
	d->owner = owner;
}
