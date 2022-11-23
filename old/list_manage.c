#include "lists.h"

/**
 * delete_dnodeint_at_index - at a given index.
 * @head: A pointer to the head of the dlistint_t.
 * @index: The index of the node to delete.
 * Return: Upon success - 1.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp = *head;

	if (*head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (tmp == NULL)
			return (-1);
		tmp = tmp->next;
	}

	if (tmp == *head)
	{
		*head = tmp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}

	else
	{
		tmp->prev->next = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = tmp->prev;
	}

	free(tmp);
	return (1);
}

void move_to_end(dlistint_t **list_pointer)
{
    while ((*list_pointer)->next)
	*list_pointer = (*list_pointer)->next;      
}

void move_to_start(dlistint_t **list_pointer)
{
    while ((*list_pointer)->prev)
	*list_pointer = (*list_pointer)->prev;      
}
