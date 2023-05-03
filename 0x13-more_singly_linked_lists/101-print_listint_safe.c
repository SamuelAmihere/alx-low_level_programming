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
	const listint_t *curr, *checker
	size_t count = 0;

	curr = h;
	if (!curr)
		exit(98);
	while (curr)
	{
		printf("[%p] %d\n", (void *)curr, curr->n);
		count += 1;

		checker = curr->next;
		while (checker)
		{
			if (checker == curr)
			{
				printf("-> [%p] %d\n", (void *) checker,
						checker->n);
				break;
			}
			checker = checker->next;
		}

		curr = curr->next;
	}

	return (count);
}
