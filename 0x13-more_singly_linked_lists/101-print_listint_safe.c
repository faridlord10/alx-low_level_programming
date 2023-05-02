#include "lists.h"

/**
 * free_listp - empty a linked list.
 * @head: head of a list.
 * Return: no return.
 */

void free_listp(listp_t **head)
{
	listp_t *tmp;
	listp_t *current;

	if (head != NULL)
	{
		current = *head;
		while ((tmp = current) != NULL)
		{
			current = current->next;
			free(tmp);
		}
		*head = NULL;
	}
}

/**
 * print_listint_safe - puts a linked list.
 * @head: head of a list.
 * Return: number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t n_node = 0;
	listp_t *hp, *new, *add;

	hp = NULL;
	while (head != NULL)
	{
		new = malloc(sizeof(listp_t));
		if (new == NULL)
			exit(98);

		new->p = (void *)head;
		new->next = hp;
		hp = new;

		add = hp;

		while (add->next != NULL)
		{
			add = add->next;
			if (head == add->p)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free_listp(&hp);
				return (n_node);
			}
		}

		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		n_node++;
	}

	free_listp(&hp);
	return (n_node);
}
