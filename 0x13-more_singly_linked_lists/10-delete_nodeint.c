#include "lists.h"
#include <stdlib.h>


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

	if (index == 0 && *head == NULL)
		return (-1);
	else if (index == 0 && (*head))
	{
		prev = *head;
		*head = (*head)->next;
		free(prev);
		return (1);
	}
	else
	{
		curr = (*head)->next;
		while (curr && i < index)
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
	}

	return (-1);

}
