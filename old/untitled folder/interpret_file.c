#include "monty.h"

void interpret_file(char (*file_buffer)[MAX_NUM_LINES])
{
    int i = 0;
    int contains_opcode;

    Sstack_t *top_of_stack = NULL;
    Sstack_t floor = {FLOOR, NULL, NULL};

    instruct_t *opcode_chart = NULL;
    fill_chart_in(&opcode_chart);

    do 
    {
        contains_opcode = find_opcode(&opcode_chart, file_buffer[i]);
        if (contains_opcode)
            printf("WE WOULD IVOKE %s\n", opcode_chart->opcode);
        else
        {
            fprintf(stderr, BAD_INSTRUCTION, i, file_buffer[i]);
            exit(EXIT_FAILURE);
        }
        back_to_top_of_chart(&opcode_chart);
    }
    while(strlen(file_buffer[(i++) + 1]) != 0); 
}

int find_opcode(instruct_t **chart, const char *line_buffer)
{
    int positive = 0;
    while (*chart)
    {
        positive = (strstr(line_buffer, (*chart)->opcode) != NULL);
        if (positive)
            break;

        *chart = (*chart)->next;
    }
    return (positive); 
}

void back_to_top_of_chart(instruct_t **chart)
{
    while ((*chart)->prev)
        *chart = (*chart)->prev;
}
