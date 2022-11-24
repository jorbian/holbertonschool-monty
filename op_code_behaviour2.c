#include "include/monty.h"
#include "include/op_code.h"

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

/**
 * nop - does absolutely nothing.
 * @stack_pointer: Exactly what it says on the tin.
 * @line_number: Line number of current file.
*/
void nop(stack_t **stack_pointer, unsigned int line_number)
{
	(void)stack_pointer;
	(void)line_number;
}

/**
 * add - adds the top two elements of the stack.
 * @stack_pointer: Exactly what it says on the tin.
 * @line_number: Line number of current file.
*/
void add(stack_t **stack_pointer, unsigned int line_number)
{
	if ((*stack_pointer)->next == NULL || (*stack_pointer)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}
	(*stack_pointer)->next->next->n += (*stack_pointer)->next->n;
	pop(stack_pointer, line_number);
}
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