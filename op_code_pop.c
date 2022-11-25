#include "monty.h"
#include "op_code.h"

/**
 * pop - Removes the top value element of a stack_t linked list.
 * @stack_pointer: Exactly what it says on the tin.
 * @line_number: Line number of current file.
 */
void pop(stack_t **stack_pointer, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack_pointer)->next == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}

	next = (*stack_pointer)->next->next;
	free((*stack_pointer)->next);
	if (next)
		next->prev = *stack_pointer;
	(*stack_pointer)->next = next;
}
