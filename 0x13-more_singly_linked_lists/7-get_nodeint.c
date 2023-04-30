#include "lists.h"
#include <stdlib.h>

/**
 * get_nodeint_at_index - Finds the nth node of a
 *
 * @head: Starting node
 *
 * @index: location of nth node
 *
 * Return: the address of the nth node, or NULL if it failed
 */
listint_t *get_nodeint_at_index(listint_t *head,
		unsigned int index)
{
	listint_t *prev;
	listint_t *curr;
	unsigned int i = 0;

	prev = head;
	if (prev == NULL)
		return (NULL);
	if (head->next == NULL || index == 1)
		return (head);

	curr = head->next;
	while (curr && i < index)
	{
		prev = curr;
		curr = curr->next;
		i += 1;
	}
	return (prev);
}
