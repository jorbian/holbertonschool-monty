#include "monty.h"

/**
 * load_file - gets the contents of file loads it into an array.
 * @filename: the validated file name
 * Return: a double pointer to the first element in the file buffer array.
*/
void load_file(
    char (*file_buffer)[MAX_NUM_LINES],
    char *filename
)
{
    char *line_buffer = NULL;

    size_t line_buffer_size = 0;
    ssize_t line_size;
    int line_index = 0;
    FILE *file_pointer = fopen(filename, "r");
  
    if (!file_pointer)
    {
        fprintf(stderr, BAD_FILE, filename);
        exit(EXIT_FAILURE);
    }

    do 
    {
        line_size = getline(&line_buffer, &line_buffer_size, file_pointer);

        strcpy(file_buffer[line_index], line_buffer);

    } while ((strlen(file_buffer[line_index++]) != 0));

    free(line_buffer);
    line_buffer = NULL;

    fclose(file_pointer);
}
