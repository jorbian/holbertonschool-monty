#include "monty.h"

/**
 * main - entry point for the program. 
 * @args: parameters passed
 * @argv: exactly what said parameters were
 * 
 * Return: Void.
*/
int main(int argc, char *argv[])
{
    size_t max_size = (sizeof(char) * MAX_LINE_LENGTH);
    char (*file_buffer)[MAX_NUM_LINES] = malloc(max_size);
    if (!file_buffer)
    {
        printf("MALLOC FAILED");
    }

    if (argc != 2)
    {
        fprintf(stderr, BAD_INPUT);
        exit(EXIT_FAILURE);
    }

    load_file(file_buffer, argv[1]);
    interpret_file(file_buffer);

    free(file_buffer); 

    return (0);
}
