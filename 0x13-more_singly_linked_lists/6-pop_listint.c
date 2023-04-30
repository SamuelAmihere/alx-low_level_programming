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
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n = 0;

	if (head != NULL)
	{
		n = (int) (*head)->n;
		temp = *head;
		*head = (*head)->next;
		free(teimp);

		return (n);
	}
	else
		return (n);

}
