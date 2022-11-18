#include "include/monty.h"

/**
* interpret_file - placeholder
* @data: the contents of the file
*
* Return nothing for now
*/
void interpret_file(char *data)
{
	int line_number = 0;
	int current_byte_in_data = 0;
	int current_byte_on_line = 0;
	char line_buffer[MAX_LINE_SIZE];

	for (;;)
	{
		line_number++;
		current_byte_on_line = -1;

		while (data[current_byte_in_data++] != '\n')
		{
			current_byte_on_line++;
			line_buffer[current_byte_on_line] = data[current_byte_in_data - 1];
		}
		line_buffer[current_byte_on_line + 1] = '\0';

		printf("%s", find_opcode(line_buffer));

		strcpy(line_buffer, "");

		if (data[current_byte_in_data] == '\0')
			break;
	}
}
