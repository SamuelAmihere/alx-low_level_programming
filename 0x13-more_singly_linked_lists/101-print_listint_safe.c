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
	const listint_t *curr = h;
	size_t count = 0;

	while (curr)
	{
		count += 1;
		printf("[%p] %d\n", (void *)curr, curr->n);
		curr = curr->next;

		if (curr >= h && curr)
		{
			printf("-> [%p] %d\n", (void *)curr, curr->n);
			exit(98);
		}
	}

	return (count);
}
