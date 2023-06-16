#include "lists.h"

size_t dlistint_len(const dlistint_t *h);

/**
 * delete_dnodeint_at_index - Inserts a new node at a given
 * position
 *
 * @head: Starting node
 *
 * @index: location to insert node
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp, *prev, *curr;
	unsigned int i = 0;

	if (*head == NULL || index > dlistint_len(*head) - 1)
		return (-1);

	prev = *head;
	if (index == 0)
	{
		*head = (*head)->next;
		if (!(*head))
			return (-1);
		(*head)->prev = NULL;
		free(prev);
		return (1);
	}
	curr = (*head)->next;
	while (curr && i < (index - 1))
	{
		prev = curr;
		curr = curr->next;
		i++;
	}
	if (curr)
	{
		temp = curr;
		prev->next = curr->next;
		return (1);
	}

	return (-1);
}

/**
 * dlistint_len - Finds number of elements in a linked
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
