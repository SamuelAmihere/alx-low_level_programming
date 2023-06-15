#include "lists.h"

/**
 * dlistint_len - Determines number of elements in dlistint_t.
 *
 * @h: pointer to the head node of dlistint_t
 *
 * Return: Number of nodes in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	int cnt = 0;

	while (h)
	{
		cnt += 1;
		h = h->next;
	}
	return (cnt);
}
