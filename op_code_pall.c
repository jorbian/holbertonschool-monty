#include "monty.h"
#include "op_code.h"

/**
 * pall - Prints the values of a stack_t linked list.
 * @stack_pointer: Exactly what it says on the tin.
 * @line_number: Line number of current file.
 */
void pall(stack_t **stack_pointer, unsigned int line_number)
{
	stack_t *tmp = (*stack_pointer)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}
