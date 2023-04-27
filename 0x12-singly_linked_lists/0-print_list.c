#include "lists.h"
#include <stdlib.h>

/**
 * print_list - all the elements of a list.
 *
 * @h: struct whose elements to be print elememts
 *
 * Return: Number of nodes
 */
size_t print_list(const list_t *h)
{
	int count = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);

		count += 1;

		h = h->next;
	}

	return (count);
}
