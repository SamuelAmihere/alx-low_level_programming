#include "lists.h"

/**
 * get_dnodeint_at_index - Finds node at a given index of a list
 *
 * @head: Starting node
 *
 * @index: location of nth node
 *
 * Return: the address of the nth node, or NULL if it failed
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head,
		unsigned int index);
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
