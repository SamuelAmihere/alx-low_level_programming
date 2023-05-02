#include "lists.h"
#include <stdlib.h>

size_t listint_len(const listint_t *h);

/**
 * delete_nodeint_at_index - Inserts a new node at a given
 * position
 *
 * @head: Starting node
 *
 * @index: location to insert node
 *
 * Return: 1 on success, -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *prev, *curr;
	unsigned int i = 0;

	if (*head == NULL || index > listint_len(*head) - 1)
		return (-1);
	if (index == 0)
	{
		prev = *head;
		*head = (*head)->next;
		free(prev);
		return (1);
	}

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
