#include "lists.h"
#include <stdlib.h>

int add_all(listint_t *head);

/**
 * sum_listint - Finds sum of elements in a list
 *
 * @head: Starting node
 *
 * Return: Sum of elements in list, 0 if empty
 */
int sum_listint(listint_t *head)
{
	return (add_all(head));
}

/**
 * add_all - Adds all elements recursively
 *
 * @head: Starting node
 *
 * Return: Sum of elements in list, 0 if empty
 */
int add_all(listint_t *head)
{
	if (!head)
		return (0);
	if (head->next)
		return (head->n + add_all(head->next));
	else
		return (head->n);
}
