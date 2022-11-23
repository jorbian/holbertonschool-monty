#include "monty.h"

int main(int argc, char *argv[])
{
    char *file_name = argv[1];
    size_t line_size = 0;
    char *line_buffer = 0;
    char *tok1, *tok2;
    FILE *file_pointer; 

    SSTack_t *stack_pointer = NULL;
    instruct_t *chart_pointer = NULL;

    if (!argc || file_name == NULL)
    {
        printf("NO FILE NAME");
        exit(EXIT_FAILURE);
    }
    file_pointer = fopen(file_name, "r");

    build_stack(&stack_pointer);
    fill_chart_in(&chart_pointer);

    while (getline(&line_buffer, &line_size, file_pointer) != EOF)
    {
        tok1 = strtok(line_buffer, DELIMS);
        tok2 = strtok(NULL, DELIMS);
        
        if (tok2 && is_number(tok2))
        {
            move_to_end(&stack_pointer);
            stack_pointer->n = atoi(tok2);
            move_to_start(&stack_pointer);
        }
        
        while (chart_pointer)
        {
            int matches_opcode = !(strcmp(tok1, chart_pointer->opcode));
            if (matches_opcode)
                break;
            chart_pointer = chart_pointer->next;
        }

        chart_pointer->f(&stack_pointer, 23);

        begining_of_chart(&chart_pointer);
    }
}
