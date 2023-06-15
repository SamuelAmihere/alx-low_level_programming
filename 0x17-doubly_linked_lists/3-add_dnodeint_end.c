#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a linked list
 *
 * @head: starting node
 * @n: Integer to be added.
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlist_t *new, *temp;
	unsigned int len = 0;

	new = malloc(sizeof(dlist_t));
	if (!new)
		return (NULL);

	temp = *head;

	new->n = n;
	new->next  = NULL;

	if (!(*head))
	{
		new->prev = NULL;
		*head = new;
	} else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
	return (new);
}
