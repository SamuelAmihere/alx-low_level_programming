#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_nodeint - adds a new node at the beginning of a linked list
 *
 * @head: starting node
 * @n: Integer to add
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		printf("Error\n");
		return (NULL);
	}

	if (new)
	{
		new->n = n;
		new->next = *head;
		*head = new;
	}

	return (*head);
}
