#include "monty.h"

int main(int argc, char *argv[])
{
    char *file_name = argv[1];
    size_t line_size = 0;
    char *line_buffer = 0;
    char *tok1, *tok2;

    SSTack_t *stack_pointer = NULL;
    instruct_t *instruction_chart = NULL;

    FILE *file_pointer = fopen(file_name, "r");

    build_stack(&stack_pointer);

    while (getline(&line_buffer, &line_size, file_pointer) != EOF)
    {
        tok1 = strtok(line_buffer, DELIMS);
        tok2 = strtok(NULL, DELIMS);
        
        if (tok2)
        {
            move_to_end(&stack_pointer);
            stack_pointer->n = atoi(tok2);
            move_to_start(&stack_pointer);
        }
        push(&stack_pointer, 23);
        absolute_print(stack_pointer);
    }
}