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
	listint_t *tem;
	unsigned int i = 0;

	if (index > 0)
	{
		*temp = head;
		while (temp && i < index)
		{
			temp = temp->next;
		}
	}
	return (head);
}
