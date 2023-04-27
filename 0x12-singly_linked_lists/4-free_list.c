#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a list
 *
 * @head: struct freed
 *
 * Return: nothing
 */
void free_list(list_t *head)
{
	list_t *temp;

	temp = head;
	if (head)
	{
		while (head)
		{
			temp = head;
			head = head->next;

			free(temp->str);
			free(temp);
		}
	}
	free(head);
}
