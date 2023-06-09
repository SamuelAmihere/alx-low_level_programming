#include "lists.h"
#include <stdlib.h>

size_t listint_len(const listint_t *h);

/**
 * insert_nodeint_at_index - Inserts a new node at a given
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
listint_t *insert_nodeint_at_index(listint_t **head,
		unsigned int idx, int n)
{
	listint_t *new, *temp, *prev;
	unsigned int i = 0;

	new = malloc(sizeof(listint_t));

	if (!new || idx > listint_len(*head))
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
		new->next = temp;
	}
	else
	{
		new->next = *head;
		*head = new;
	}

	return (new);
}


/**
 * listint_len - Finds number of elements in a linked
 *
 * @h: struct whose elements to be print elememts
 *
 * Return: number of elements in a linked
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		count += 1;
		h = h->next;
	}

	return (count);
}
