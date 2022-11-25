#include "monty.h"
#include "op_code.h"

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
