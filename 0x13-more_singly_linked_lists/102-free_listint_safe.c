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
	listint_t *current, *new;
	size_t count = 0;

	if (!h || !*h)
		return (0);

	current = *h;

	while (current)
	{
		count++;
		new = current->next;

		if (current < new)
		{
			free(current);
			current = NULL;
		}
		else
		{
			tmp = current
			current = new;
			free(tmp);

		}
	}
	current = NULL;

	return (count);
}
