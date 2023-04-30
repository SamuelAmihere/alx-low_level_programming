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
	listint_t *temp;
	unsigned int i = 0;

	temp = head;
	if (!temp)
		return (NULL);

	while (temp && i < index)
	{
		temp = temp->next;
		i += 1;
	}
	return (temp);
}
