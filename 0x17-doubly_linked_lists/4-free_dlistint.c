#include "lists.h"

/**
 * free_dlistint - Frees a doubly linked list.
 *
 * @head: Node to free.
 *
 * Return: Nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	temp = head;
	if (head)
	{
		while (head)
		{
			temp = head;
			head = head->next;

			free(temp);
		}
	}
	free(head);
}
