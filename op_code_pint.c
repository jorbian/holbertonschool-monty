#include "monty.h"
#include "op_code.h"

/**
 * pint - Prints the top value of a stack_t linked list.
 * @stack_pointer: Exactly what it says on the tin.
 * @line_number: Line number of current file.
 */
void pint(stack_t **stack_pointer, unsigned int line_number)
{
	if ((*stack_pointer)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}
	printf("%d\n", (*stack_pointer)->next->n);
}
