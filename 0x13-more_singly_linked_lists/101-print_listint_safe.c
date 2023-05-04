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
	size_t cnt;

	cnt = 0;
	curr = h;

	if (h == NULL)
		return (cnt);

	while (curr)
	{
		printf("[%p] %d\n", (void *)curr, curr->n);
		cnt += 1;

		if ((curr->next) >= curr)
		{
			printf("-> [%p] %d\n", (void *)curr->next,
					(curr->next)->n);
			return (cnt);
		}
		curr = curr->next;

		if (cnt % 2 == 0 && cnt > 2 && curr == h)
		{
			printf("-> [%p] %d\n", (void *)curr, curr->n);
			return (cnt);
		}

	}

	return (cnt);
}
