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
	size_t count = 0;


	while (h)
	{
		if (!h->n)
			exit(98);
		else
		{
			printf("[%p] %d\n", (void *)h, h->n);
			count += 1;
			h = h->next;
		}
	}

	return (count);
}
