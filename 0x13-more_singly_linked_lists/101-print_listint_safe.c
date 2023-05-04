#include "lists.h"
#include <stdio.h>

/**
 * loop_check - function that checks if a linked list contains a loop.
 *
 * @head: pointer to head of a list.
 *
 * Return: 1 if loop is present, 0 if not.
 */
int loop_check(const listint_t *head)
{
	const listint_t *slow_p = head, *fast_p = head;

	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			printf("-> [%p] %d\n", (void *)head, head->next->n);
			return (1);
		}
	}
	return (0);
}

/**
 * print_listint_safe - prints a listint_t linked list
 *
 * @h: pointer first node in list
 *
 * Return: Number of nodes in the list
 */
size_t print_listint_safe(const listint_t *h)
{
	size_t ele = 0;

	if (!h)
		return (0);

	if (loop_check(h))
		return (0);

	while (h)
	{
		cnt++;
		printf("[%p] %d\n", (void *)h, h->n);
		h = h->next;
	}
	return (cnt);
}
