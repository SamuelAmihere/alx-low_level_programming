#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - adds a new node at the end of a linked list
 *
 * @head: starting node
 * @n: integer to add
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *temp;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		printf("Error\n");
		return (NULL);
	}

	temp = *head;
	new->n = n;
	new->next = NULL;

	if (!*head)
		*head = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}
