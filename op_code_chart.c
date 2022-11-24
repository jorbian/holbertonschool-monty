#include "include/monty.h"
#include "include/op_code.h"

/**
 * build_instruct_chart - create the instruction chart.
 * @top_of_chart: pointer to the top of the chart.
 *
 * Return: nothing for now.
 */
void fill_chart_in(instruct_t **top_of_chart)
{
	int i;
	char opcodes[NUM_OF_OPS][NAME_BUFFER_SIZE] = OPCODE_NAMES;
	void (*fps[NUM_OF_OPS])(stack_t **, unsigned int) = FUNCTIONS;

	for (i = 0; i < NUM_OF_OPS; i++)
		create_instruction(top_of_chart, opcodes[i], fps[i]);
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
 * look_up_instruction - 
 * @chart_pointer: adsf 
 * @token: asfd 
 * 
 * Return: 
*/
void (*look_up_instruction(instruct_t **chart_pointer, char *token))(stack_t**, unsigned int)
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