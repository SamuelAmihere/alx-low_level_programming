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
		prev = *head;
		*head = (*head)->next;
		free(prev);
		return (1);
	}

	prev = *head;
	curr = (*head)->next;
	while (curr && i < (index - 1))
	{
		prev = curr;
		curr = curr->next;
		i += 1;
	}

	if (curr)
	{
		temp = curr;
		prev->next = curr->next;
		free(temp);
		return (1);
	}

	return (-1);
}
