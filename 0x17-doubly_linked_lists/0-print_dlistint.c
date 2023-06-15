#include "lists.h"

/**
 * print_dlistint - prints  all the elements of a dlistint_t
 *
 * @h: pointer to the head node of dlistint_t
 *
 * Return: Number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	int cnt;

	cnt = 0;

	while (h)
	{
		printf("%d\n", h->n);
		cnt += 1;
		h = h->next;
	}
	return (cnt);
}
