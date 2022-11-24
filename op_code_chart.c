#include "monty.h"
#include "op_code.h"

/**
 * fill_chart_in - create the instruction chart.
 * @top_of_chart: pointer to the top of the chart.
 *
 * Return: 1 if it managed to fill the chart in. 0 otherwise.
 */
int fill_chart_in(instruct_t **top_of_chart)
{
	int i;

	char opcodes[NUM_OF_OPS][NAME_BUFFER_SIZE] = OPCODE_NAMES;

	void (*fps[NUM_OF_OPS])(stack_t **, unsigned int) = FUNCTIONS;

	for (i = 0; i < NUM_OF_OPS; i++)
	{
		if (!(create_instruction(top_of_chart, opcodes[i], fps[i])))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * create_instruction - add another instruction to the chart
 * @last_entry: double pointer to the previous entry on the chart
 * @next_opcode: name of the next opcode to be created as a string
 * @next_fp: pointer to the function to be invoked by that opcode
 *
 * Return: The address of the new instruction.
 */
instruct_t *create_instruction(
	instruct_t **last_entry,
	const char *next_opcode,
	void (*next_fp)(stack_t **, unsigned int)
)
{
	instruct_t *current_entry;
	char *temp_string;

	current_entry = malloc(sizeof(instruct_t));
	if (!current_entry)
		return (NULL);

	temp_string = strdup(next_opcode);

	current_entry->opcode = temp_string;
	current_entry->f = next_fp;
	current_entry->prev = NULL;
	current_entry->next = *last_entry;

	if (*last_entry != NULL)
		(*last_entry)->prev = current_entry;
	*last_entry = current_entry;

	return (current_entry);
}

/**
 * look_up_instruction - look for the opcode on the chart
 * @chart_pointer: exactly what it says on the tin
 * @token: the token found on the line.
 * Return:
*/
void (*look_up_instruction(
	instruct_t **chart_pointer,
	char *token
	))(stack_t**, unsigned int)
{
	instruct_t *current_entry = *chart_pointer;

	while (current_entry->next)
	{
		if (strcmp(token, current_entry->opcode) == 0)
			break;
		current_entry = current_entry->next;
	}

	if (current_entry)
		return (current_entry->f);
	else
		return (NULL);
}

/**
 * erasse_chart - frees the instruction chart from memory
 * @hchart_pointer: Exactly what it says on the tin.
 */
void erasse_chart(instruct_t *chart_pointer)
{
	instruct_t  *tmp;

	while (chart_pointer)
	{
		tmp = chart_pointer->next;
		free(chart_pointer->opcode);
		free(chart_pointer);
		chart_pointer = tmp;
	}
}
