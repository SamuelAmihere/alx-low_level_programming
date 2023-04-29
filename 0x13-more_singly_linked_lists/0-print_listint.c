#include "lists.h"
#include <stdlib.h>

/**
 * print_listint - Prints all the elements of a list.
 *
 * @h: struct whose elements to be print elememts
 *
 * Return: Number of nodes
 */
size_t print_listint(const listint_t *h)
{
	int count = 0;

	while (h)
	{
		count += 1;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (count);
}
