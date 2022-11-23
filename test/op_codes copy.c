#include "monty.h"

void push(SSTack_t  **stack_pointer, unsigned int line_number)
{
    int temp_value = 0;
    int contains_num = 0;

    (void)line_number;

    move_to_end(stack_pointer);

    temp_value = (*stack_pointer)->n;
    contains_num = (temp_value != FLAG);

    if (contains_num)
    {
        (*stack_pointer)->n = FLAG;
        move_to_start(stack_pointer);
        absolute_push(stack_pointer, temp_value);
    }
}


void pall(SSTack_t  **stack_pointer, unsigned int line_number)
{
    (void)line_number;

    while ((*stack_pointer)->n != FLOOR)
    {
        printf("%d", (*stack_pointer)->n);
        *stack_pointer = (*stack_pointer)->next;
    }
}

void pint(SSTack_t  **stack_pointer, unsigned int line_number)
{
    (void)stack_pointer;
    (void)line_number;
}

void pop(SSTack_t  **stack_pointer, unsigned int line_number)
{
    (void)stack_pointer;
    (void)line_number;
}

void swap(SSTack_t  **stack_pointer, unsigned int line_number)
{
    (void)stack_pointer;
    (void)line_number;
}

void nop(SSTack_t  **stack_pointer, unsigned int line_number)
{
    (void)stack_pointer;
    (void)line_number;
}
