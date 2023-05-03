#include "lists.h"
#include <stdlib.h>


/**
 * find_listint_loop - finds a loop
 *
 * @h: pointer first node in list
 *
 * Return: Number of nodes in the list
 */
listint_t *find_listint_loop(listint_t *h)
{
	listint_t *curr, *temp;
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
			break;
		}

	}


	return (*h);
}
