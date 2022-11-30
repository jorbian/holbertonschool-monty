#include "include/monty.h"

/**
 * create_command_parser - exactly what it says on the tin
 * @self: double pointer to the command parser itself
 *
 * Return: Whether or not it failed, EXIT_SUCESS or EXIT_FAILURE
 */
int create_parser(CommandParser_t **self)
{
	(*self)->raw_input = malloc(sizeof(char) * MAX_INPUT_BUFF);
	if ((*self)->raw_input == NULL)
		return (throw_error(COULDNT_MALLOC, 0, ""));

	(*self)->error_tripped = 0;

	(*self)->table = malloc(sizeof(CommandTable_t));
	if ((*self)->table == NULL)
		return (throw_error(COULDNT_MALLOC, 0, ""));

	(*self)->tokens = NULL;

	return (EXIT_SUCCESS);
}
/**
 * take_input - take a new line of input to be parsed
 * @self: double pointer to the command parser itself
 * @new_input: the new line of input as one string
 *
 * Return: Whether or not it failed, EXIT_SUCESS or EXIT_FAILURE
 */
int move_line(CommandParser_t **self, char *new_input)
{
	if (((*self)->raw_input) == NULL)
	{
		(*self)->raw_input = malloc(sizeof(char) * MAX_INPUT_BUFF);
		if ((*self)->raw_input == NULL)
			return (EXIT_FAILURE);
	}
	snprintf(((*self)->raw_input), MAX_INPUT_BUFF, "%s", new_input);

	return (EXIT_SUCCESS);
}
/**
 * parse_line - parse the line of raw input currently in parser
 * @self: double pointer to the command parser itself
 *
 * Return: Whether or not it failed, EXIT_SUCESS or EXIT_FAILURE
*/
int parse_line(CommandParser_t **self)
{
	char *token;
	char *save_pointer = (*self)->raw_input;
	int error_status = 0;

	while ((token = strtok_r(save_pointer, DELIMS, &save_pointer)))
	{
		error_status = !(add_to_end(&((*self)->tokens), token));
		if (error_status)
			return (EXIT_FAILURE);
	}
}
/**
 * free_parser - free whatever memory that was allocated for the parser
 * and its various members.
 * @self: double pointer to the command parser itself
*/
void free_parser(CommandParser_t **self)
{
	if ((*self)->raw_input)
		free((*self)->raw_input);
	if ((*self)->tokens)
		free_stringbuff((*self)->tokens);
	free(*self);
}
