#include <stdlib.h>
#include <stdio.h>
#include "dog.h"


/**
 * print_dog - print a dog object
 *
 * @d: dog pointer
 *
 * Return: nothing
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;
	if (d->name == NULL)
		printf("name: (nil)");
	if (d->owner == NULL)
		printf("owner: (nil)");

	printf("Name: %s\nAge: %10.6f\nOwner: %s\n", d->name
			, d->age, d->owner);
}
