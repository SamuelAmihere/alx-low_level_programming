#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a dlinked list.
 *
 * @head: Starting node.
 * @n: Integer to be added.
 *
 * Return: Address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;

	if (!(*head))
	{
		new->prev = NULL;
		new->next = NULL;
	} else
	{
		new->prev = (*head)->prev;
		new->next = *head;
		(*head)->prev = new;
	}
	*head = new;

	return (*head);
}
