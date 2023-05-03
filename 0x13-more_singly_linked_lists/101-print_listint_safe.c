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
	size_t count;

	count = 0;

	while (h)
	{
		printf("[%p] %d\n", (void *)h, h->n);
		count += 1;

		if ((h->next) >= h)
		{
			printf("-> [%p] %d\n", (void *)h->next,
					(h->next)->n);
			break;
		}
		h = h->next;

	}

	return (count);
}
