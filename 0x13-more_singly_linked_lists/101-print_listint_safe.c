#include "lists.h"
#include <stdlib.h>


/**
 * print_listint_safe - prints a listint_t linked list
 *
 * @h: pointer first node in list
 *
 * Return: Number of nodes in the list
 */
size_t print_listint_safe(const listint_t *h)
{
	const listint_t *curr, *temp;
	size_t count = 0;

	curr = h;
	if (!curr)
		exit(98);

	while (curr)
	{
		temp = curr;
		curr = curr->next;
		count += 1;
		printf("[%p] %d\n", (void *)temp, temp->n);

		if (temp < curr)
		{
			printf("-> [%p] %d\n", (void *)curr, curr->n);
			exit(98);
		}

	}


	return (count);
}
