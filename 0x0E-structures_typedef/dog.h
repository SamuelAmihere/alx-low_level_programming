#ifndef DOG_H
#define DOG_H

/**
 * struct dog - defining a dog
 *
 * @name: name of dog
 * @age: age of dog
 * @owner: dog's owner
 *
 * Description: Further description of dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);

#endif
