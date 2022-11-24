#include "monty.h"
#include "op_code.h"

/**
 * interpret_script - Primary function to execute a Monty bytecodes script.
 * @file_pointer: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int interpret_script(FILE *file_pointer)
{
	stack_t *stack_pointer = NULL;
	instruct_t *chart_pointer = NULL;

	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	fill_chart_in(&chart_pointer);
	if (initialize_stack(&stack_pointer) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, file_pointer) != -1)
	{
		line_number++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			wipe_stack(&stack_pointer);
			return (malloc_error());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			free_tokens();
			continue;
		}
		op_func = look_up_instruction(&chart_pointer, op_toks[0]);
		if (op_func == NULL)
		{
			wipe_stack(&stack_pointer);
			exit_status = unknown_op_error(op_toks[0], line_number);
			free_tokens();
			break;
		}
		prev_tok_len = num_of_tokens();
		op_func(&stack_pointer, line_number);
		if (num_of_tokens() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	wipe_stack(&stack_pointer);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}

	free(line);
	return (exit_status);
}
