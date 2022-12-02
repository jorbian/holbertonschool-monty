#include "monty.h"

/**
 * create_script_buffer - exactly what it says on the tin
 * @self: double pointer back to the script buffer
 *
 * Return: If there was a problem creating bufffer --
 *			As always: 1 for 'Yes,' and 0 for 'No' --
*/
int create_script_buffer(ScriptBuffer_t **self)
{
	*self = malloc(sizeof(ScriptBuffer_t));
	if (*self == NULL)
		return (throw_error(COULDNT_MALLOC, 0, ""));

	(*self)->curr_line = malloc(sizeof(StringBuffer_t));
	if ((*self)->curr_line  == NULL)
		return (throw_error(COULDNT_MALLOC, 0, ""));

	(*self)->curr_line_num = 0;
	(*self)->error_tripped = 0;

	return (EXIT_SUCCESS);
}
/**
 * load_script_from_file - read the contents of a file line by line into buffer
 * @self: double pointer back to the script buffer
 * @file_name: name of the file to be loaded.
*/
void load_script_from_file(ScriptBuffer_t **self, char *file_name)
{
	FILE *file_pointer;
	char *new_line = NULL;
	size_t size_of_line;
	int error_status = EXIT_SUCCESS;

	StringBuffer_t *line_buffer = NULL;

	line_buffer = malloc(sizeof(StringBuffer_t));
	if (line_buffer == NULL)
	{
		(*self)->error_tripped = throw_error(COULDNT_MALLOC, 0, "");
		return;
	}
	line_buffer = (*self)->curr_line;

	file_pointer = fopen(file_name, "r");
	if (file_pointer == NULL)
	{
		(*self)->error_tripped = throw_error(BAD_FILE, 0, "");
		return;
	}
	if (error_status == EXIT_SUCCESS)
	{
		while ((getline(&new_line, &size_of_line, file_pointer) != EOF))
		{
			line_buffer = add_to_end(&line_buffer, new_line);
			if (new_line == NULL)
			{
				error_status = throw_error(COULDNT_MALLOC, 0, "");
				break;
			}
		}
		fclose(file_pointer);
	}
	(*self)->error_tripped = error_status;
	free(line_buffer);
}

/**
 * pop_line - pops the current line from the linebuffer
 * @self: double pointer back to ScriptBuffer
 *
 * Description: -- WARNING DESCTRUCTIVE --
 * Return: The current line the buffer was pointing to.
 */
char *pop_line(ScriptBuffer_t **self)
{
	char *return_string = NULL;

	return_string = strdup(pop(&(*self)->curr_line));
	if (return_string == NULL)
		(*self)->error_tripped = EXIT_FAILURE; 
	((*self)->curr_line_num)++;

	return (return_string);
}

/**
 * free_script - deallocates memory from ScriptBuffer
 * @self: double pointer back to ScriptBuffer
 *
 */
void free_script(ScriptBuffer_t **self)
{
	if ((*self)->curr_line)
		free_stringbuff((*self)->curr_line);
	free(*self);
}
