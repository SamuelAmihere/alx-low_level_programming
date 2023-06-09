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
	unsigned int i;

	if (*head == NULL || head == NULL || index >= dlistint_len(*head))
		return (-1);

	while ((*head)->prev != NULL)
		*head = (*head)->prev;

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}
	prev = *head;
	curr = (*head)->next;
	i = 0;
	while (curr && i < index - 1)
	{
		prev = curr;
		curr = curr->next;
		i++;
	}
	if (curr)
	{
		temp = curr;
		if (curr->next != NULL && curr->next->prev != NULL)
			(curr->next)->prev = prev;
		prev->next = curr->next;
		free(temp);
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
