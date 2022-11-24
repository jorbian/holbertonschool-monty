#include "include/monty.h"

/**
 * wipe_stack - frees stack from memory
 * @stack_pointer: exactly what it says on the tin.
 */
void wipe_stack(stack_t **stack_pointer)
{
	stack_t *tmp = *stack_pointer;

	while (*stack_pointer)
	{
		tmp = (*stack_pointer)->next;
		free(*stack_pointer);
		*stack_pointer = tmp;
	}
}

/**
 * initialize_stack- Initializes the stack_t stack
 * @stack_pointer: exactly what it says on the tin.
 * Return: Either 1, for sucess or NULL for failure.
 */
int initialize_stack(stack_t **stack_pointer)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = 0;
	s->prev = NULL;
	s->next = NULL;

	*stack_pointer = s;

	return (EXIT_SUCCESS);
}
