#include "monty.h"
#include "op_code.h"

/**
 * add - adds the top two elements of the stack.
 * @stack_pointer: Exactly what it says on the tin.
 * @line_number: Line number of current file.
*/
void add(stack_t **stack_pointer, unsigned int line_number)
{
	if ((*stack_pointer)->next == NULL || (*stack_pointer)->next->next == NULL)
	{
		set_op_tok_error(throw_error(CANT_ADD, line_number, ""));
		return;
	}
	(*stack_pointer)->next->next->n += (*stack_pointer)->next->n;
	pop(stack_pointer, line_number);
}
