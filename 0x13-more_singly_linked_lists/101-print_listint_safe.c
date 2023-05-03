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
	const listint_t *curr;
	size_t count;

	count = 0;
	curr = h;

	if (curr)
	{
		while (curr)
		{
			printf("[%p] %d\n", (void *)curr, curr->n);
			count += 1;

			if ((curr->next) >= curr)
			{
				printf("-> [%p] %d\n", (void *)curr->next,
						(curr->next)->n);
				break;
			}
			curr = curr->next;

		}
	}

	return (count);
}
