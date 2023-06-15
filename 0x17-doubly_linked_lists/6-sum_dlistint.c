#include "lists.h"

int add_all(dlistint_t *head);

/**
 * sum_dlistint - Finds sum of elements in a doubly linked list
 *
 * @head: Starting node
 *
 * Return: Sum of elements in list, 0 if empty
 */
int sum_dlistint(dlistint_t *head)
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
int add_all(dlistint_t *head)
{
	if (!head)
		return (0);
	if (head->next)
		return (head->n + add_all(head->next));
	else
		return (head->n);
}
