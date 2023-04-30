#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 *  pop_listint- Deletes head node of a list
 *
 * @head: starting node
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t pop_listint(listint_t **head)
{
	listint_t *temp;

	if (!head)
		return (0);
	temp = (*head)->next;
	if (head)
	{
		*head = temp;
		return (*head);
	}
}
