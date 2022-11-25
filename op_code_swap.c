#include "monty.h"
#include "op_code.h"

/**
 * swap - Swaps the top two value elements of a stack_t linked list.
 * @stack_pointer: Exactly what it says on the tin.
 * @line_number: Line number of current file.
 */
void swap(stack_t **stack_pointer, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack_pointer)->next == NULL || (*stack_pointer)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}

	tmp = (*stack_pointer)->next->next;
	(*stack_pointer)->next->next = tmp->next;
	(*stack_pointer)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack_pointer)->next;
	tmp->next = (*stack_pointer)->next;
	tmp->prev = *stack_pointer;
	(*stack_pointer)->next = tmp;
}
