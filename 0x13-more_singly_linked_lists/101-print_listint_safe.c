#include "lists.h"
#include <stdlib.h>


/**
 * print_listint_safe - prints a listint_t linked list
 *
 * @h: pointer first node in list
 *
 * Return: Number of nodes in the list
 */
size_t print_listint_safe(const listint_t *h)
{
	const listint_t *loop_node = find_listint_loop(head);

	if (loop_node == NULL)
		return (print_listint(head));

	return (print_listint_loop(head, loop_node));
}

/**
 * find_listint_loop - finds a loop in a listint_t linked list
 *
 *  @head: pointer to the first node in the list
 *
 *  Return: pointer to the node where the loop starts, or NULL if no loop
 */
const listint_t *find_listint_loop(const listint_t *head)
{
	const listint_t *slow_p = head, *fast_p = head;

	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
		{
			slow_p = head;
			while (slow_p != fast_p)
			{
				slow_p = slow_p->next;
				fast_p = fast_p->next;
			}
			return (slow_p);
		}
	}
	return (NULL);
}

/**
 * print_listint - prints a listint_t linked list from a given head
 *
 * @head: pointer to the first node in the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint(const listint_t *head)
{
	size_t cnt = 0;

	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		cnt += 1;
		head = head->next;
	}
	return (cnt);
}

/**
 * print_listint_loop - prints a listint_t linked list with a loop
 *
 * @head: pointer to the first node in the list
 *
 * @loop_node: pointer to the node where the loop starts
 *
 * Return: number of nodes in the list before the loop
 */
size_t print_listint_loop(const listint_t *head, const listint_t *loop_node)
{
	size_t cnt = 0;

	while (head != loop_node)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		cnt += 1;
		head = head->next;
	}

	printf("[%p] %d\n", (void *)loop_node, loop_node->n);
	printf("-> [%p] %d\n", (void *)loop_node->next, loop_node->next->n);

	cnt += 1;

	head = loop_node->next;
	while (head != loop_node)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		cnt += 1;
		head = head->next;
	}

	return (cnt);
}
