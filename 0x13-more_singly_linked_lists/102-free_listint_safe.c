#include "lists.h"
#include <stdlib.h>


/**
 * free_listint_safe - frees a list
 *
 * @h: pointer first node in list
 *
 * Return: Number of nodes in the list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *curr, *temp;
	size_t count = 0;

	curr = *h;
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


	return (count);
}
