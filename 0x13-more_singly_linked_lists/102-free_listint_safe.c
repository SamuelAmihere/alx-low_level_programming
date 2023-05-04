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
	listint_t *curr, *tmp = NULL;
	size_t count = 0;

	if (!h || !*h)
		return (count);

	curr = *h
	while (curr)
	{
		count++;

		if (curr < (*h)->next)
		{
			free(curr);
			curr = NULL;
		}
		else
		{
			tmp = curr;
			curr = (curr)->next;
			free(tmp);

		}
	}
	curr = NULL;

	return (count);
}
