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

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	prev = *head;
	curr = (*head)->next;
	while (curr && i < index)
	{
		prev = curr;
		curr = curr->next;
		i++;
	}

	if (curr)
	{
		prev->next = curr->next;
		if (curr->next)
			curr->next->prev = prev;
		free(curr);
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
