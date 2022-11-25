#include "monty.h"
/**
 * interpret_script - Primary function to execute a Monty bytecodes script.
 * @file_pointer: File descriptor for an open Monty bytecodes script.
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

	if (fill_chart_in(&chart_pointer) || initialize_stack(&stack_pointer))
		exit((throw_error(COULDNT_MALLOC, 0, "")));

	while (getline(&line, &len, file_pointer) != -1)
	{
		line_number++;
		op_toks = strtow(line, DELIMS);

		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_memory(stack_pointer, chart_pointer);
			exit((throw_error(COULDNT_MALLOC, 0, "")));
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			free_tokens();
			continue;
		}
		op_func = look_up_instruct(&chart_pointer, op_toks[0]);
		if (op_func == NULL)
		{
			free_tokens();
			free_memory(stack_pointer, chart_pointer);
			exit(throw_error(BAD_INSTRUCTION, line_number, op_toks[0]));
		}
		prev_tok_len = num_of_tokens();
		op_func(&stack_pointer, line_number);

		if (num_of_tokens() != prev_tok_len)
		{
			free_tokens();
			free_memory(stack_pointer, chart_pointer);
			exit(EXIT_FAILURE);
		}
		free_tokens();
	}
	free_memory(stack_pointer, chart_pointer);

	if (line && *line == 0)
	{
		free(line);
		return (throw_error(COULDNT_MALLOC, 0, ""));
	}
	free(line);
	return (exit_status);
}