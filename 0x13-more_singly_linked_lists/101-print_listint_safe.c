#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - Counts the total number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check the code.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *black, *white;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	black = head->next;
	white = (head->next)->next;

	while (white)
	{
		if (black == white)
		{
			black = head;
			while (black != white)
			{
				nodes++;
				black = black->next;
				white = white->next;
			}

			black = black->next;
			while (black != white)
			{
				nodes++;
				black = black->next;
			}

			return (nodes);
		}

		black = black->next;
		white = (white->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a safe listint_t list.
 * @head: A pointer to the head of listint_t list.
 *
 * Return: The total number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}
