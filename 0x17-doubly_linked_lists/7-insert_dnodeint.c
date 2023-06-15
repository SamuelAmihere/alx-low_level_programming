#include "lists.h"

size_t dlistint_len(const dlistint_t *h);

/**
 * insert_dnodeint_at_index - Inserts a new node at a given
 * position
 *
 * @head: Starting node
 *
 * @idx: location to insert node
 *
 * @n: number to add to list
 *
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **head,
		unsigned int idx, int n)
{
	dlistint_t *new, *temp, *prev;
	unsigned int i = 0;

	new = malloc(sizeof(dlistint_t));

	if (!new || idx > dlistint_len(*head))
		return (NULL);

	new->n = n;
	new->next = NULL;

	prev = NULL;
	temp = *head;
	while (temp && i < idx)
	{
		prev = temp;
		temp = temp->next;
		i += 1;
	}

	if (prev)
	{
		prev->next = new;
		new->prev = prev;
		new->next = temp;
		temp->prev = new;
	}
	return (new);
}

/**
 * dlistint_len - Finds number of elements in a dlinked list
 *
 * @h: struct whose elements to be print elememts
 *
 * Return: number of elements in a linked
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h)
	{
		count += 1;
		h = h->next;
	}

	return (count);
}
