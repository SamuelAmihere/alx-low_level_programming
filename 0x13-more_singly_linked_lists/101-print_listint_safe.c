#include "lists.h"

/**
 * print_listint_safe - prints nodes in linked list.
 *
 * @h: pointer to the first list.
 *
 * Return: number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *h)
{
	size_t cnt = 0;
	const listint_t *temp = h;

	if (!h)
		exit(98);

	while (temp)
	{
		cnt += 1;
		printf("[%p] %i\n", (void *)temp, temp->n);
		temp = temp->next;
	}
	return (cnt);
}
