#include "include/monty.h"

/**
* get_file - try to find a file with the name the user gave
* @filename: whatever the value of argv[1] was
*
* Return: contents of the file
*/
char *get_file(char *filename)
{
	char *raw_data;
	int buffer_size;
	FILE *file_pointer;

	int not_usable_input = !(is_usable_input(filename));

	if (not_usable_input)
		throw_error(BAD_FILE);

	file_pointer = fopen(filename, "rb");

	fseek(file_pointer, 0, SEEK_END);

	buffer_size = ftell(file_pointer);

	fseek(file_pointer, 0, SEEK_SET);

	raw_data = malloc(buffer_size);
	if (raw_data == NULL)
	{
		throw_error(COULDNT_MALLOC);
        }

	fread(raw_data, 1, buffer_size, file_pointer);

	fclose(file_pointer);
	
	return (raw_data);
}

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

/**
* throw_error - display the specified error message and exit_failure
* @message: error message to be displayed
*/
void throw_error(char *message)
{
	printf("%s", message);
	exit(EXIT_FAILURE);
}

