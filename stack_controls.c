#include "monty.h"

SSTack_t *absolute_push(SSTack_t **stack_pointer, const int n)
{
	SSTack_t *new;

	new = malloc(sizeof(SSTack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *stack_pointer;
	if (*stack_pointer != NULL)
		(*stack_pointer)->prev = new;
	*stack_pointer = new;

	return (new);
}

void build_stack(SSTack_t **stack_pointer)
{
    absolute_push(stack_pointer, FLAG);
    absolute_push(stack_pointer, FLOOR); 
}

void absolute_print(const SSTack_t *stack_pointer)
{
	while (stack_pointer)
    {
        printf("%d\n", stack_pointer->n);
		stack_pointer = stack_pointer->next;
    }
}

void move_to_start(SSTack_t **stack_pointer)
{
    while ((*stack_pointer)->prev)
        *stack_pointer = (*stack_pointer)->prev;
}
void move_to_end(SSTack_t **stack_pointer)
{
    while ((*stack_pointer)->next)
        *stack_pointer = (*stack_pointer)->next;
}
