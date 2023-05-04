#include "lists.h"
#include <stdlib.h>


/**
 * free_listint_safe - frees a list
 *
 * @h: pointer first node in list
 *
 * Return: Number of nodes in the list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *tmp;
	size_t count = 0;

	while (*h)
	{
		count++;

		if (*h < (*h)->next)
		{
			free(*h);
			*h = NULL;
		}
		else
		{
			tmp = *h;
			*h = (*h)->next;
			free(tmp);

		}
	}
	*head = NULL;

	return (count);
}
