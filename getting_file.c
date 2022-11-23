#include "monty.h"

/**
* is_usable_input - make sure the file exists before we try to read it
* @input_string: a pointer to whatever the value of argv[1] was
*
* Return: 1  if it exists and has the right name, 0  otherwise
*/
int is_usable_input(char *filename)
{
        int is_valid_file;

        int file_exists  = !(access(filename, F_OK));
        int we_can_read_it = !(access(filename, R_OK));
        char *has_right_extensionn = strstr(filename, EXTENSION);

        is_valid_file = (
                file_exists && we_can_read_it && has_right_extensionn
        );

        return(is_valid_file);
}

void load_file(buffer_t **buffer_pointer, char *filename)
{
    size_t line = 0, nchars = 32;
    char *line_buffer = NULL;

    FILE *file_pointer = fopen(filename, "r");

    if (!file_pointer)
        printf("FAILED TO LOAD");
    
    while (getline(&line_buffer, &nchars, file_pointer) != EOF && ++line)
        add_line(buffer_pointer, line_buffer);
}

buffer_t *add_line(buffer_t **buffer_pointer, char *line)
{
	buffer_t *new;

	new = malloc(sizeof(buffer_t));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->prev = NULL;
	new->next = *buffer_pointer;
	if (*buffer_pointer != NULL)
		(*buffer_pointer)->prev = new;
	*buffer_pointer = new;

	return (new);
}

void wipe_buffer(buffer_t *buffer_pointer)
{
	buffer_t *tmp;

	while (buffer_pointer)
	{
		tmp = buffer_pointer->next;
		free(buffer_pointer);
		buffer_pointer = tmp;
	}
}

void find_begining_of_file(buffer_t **buffer_pointer)
{
    while (*buffer_pointer)
        *buffer_pointer = (*buffer_pointer)->prev;
}
