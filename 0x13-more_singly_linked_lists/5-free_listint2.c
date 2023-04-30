#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - frees a list
 *
 * @head: struct freed
 *
 * Return: nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	temp = *head;
	if (*head)
	{
		while (*head)
		{
			temp = *head;
			*head = (*head)->next;

			free(temp);
		}
	}
	*head = NULL;
}
