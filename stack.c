#include "monty.h"

/**
 * free memory- frees stack from memory
 * @stack_pointer: exactly what it says on the tin.
 * @chart_pointer: exactly what it says on the tin
 */
void free_memory(stack_t *stack_pointer, instruct_t *chart_pointer)
{
	stack_t *tmp1 = stack_pointer;
	instruct_t *tmp2;

	while (stack_pointer)
	{
		tmp1 = stack_pointer->next;
		free(stack_pointer);
		stack_pointer = tmp1;
	}

	while (chart_pointer)
	{
		tmp2 = chart_pointer->next;
		free(chart_pointer->opcode);
		free(chart_pointer);
		chart_pointer = tmp2;
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
		return (throw_error(COULDNT_MALLOC, 0, ""));

	s->n = 0;
	s->prev = NULL;
	s->next = NULL;

	*stack_pointer = s;

	return (EXIT_SUCCESS);
}
