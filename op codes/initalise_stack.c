#include "lists.h"

#define FLAG -2147483646
#define FLOOR -2147483647

void initalise_stack(dlistint_t **stack_pointer);

void push(dlistint_t **stack_pointer, int line);
void pall(dlistint_t **stack_pointer, int line);

int main()
{
	int i;

	dlistint_t *stack_pointer;
	stack_pointer = NULL;
	initalise_stack(&stack_pointer);

	for (i = 0; i < 5; i++)
	{
		move_to_end(&stack_pointer);
		stack_pointer->n = i;

		push(&stack_pointer, 1);
	}
	pall(&stack_pointer, 23)
}

void initalise_stack(dlistint_t **stack_pointer)
{
	add_dnodeint(stack_pointer, FLAG);
	add_dnodeint(stack_pointer, FLOOR);
}

void push(dlistint_t **stack_pointer, int line)
{
	int is_flagged = 0;
	int temp = 0;

	(void)line;

	move_to_end(stack_pointer);

	is_flagged = ((*stack_pointer)->n == FLAG);
	if (is_flagged)
	{
		printf("ERROR!!\n");
		exit(EXIT_FAILURE);
	}
	temp = (*stack_pointer)->n;
	(*stack_pointer)->n = FLAG;

	move_to_start(stack_pointer);

	add_dnodeint(stack_pointer, temp);
}

void pall(dlistint_t **stack_pointer, int line)
{
	while((*stack_pointer)->n != FLOOR)
	{
		printf("%d",(*stack_pointer)->n);
		*stack_pointer = (*stack_pointer)->prev;
	}
	move_to_start(stack_pointer);
}
