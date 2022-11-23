#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#define FLOOR -2147483647
#define FLAG -2147483646

/**
 * struct stack_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 * Description: doubly linked list node structure
 */
typedef struct SSTack_s
{
	int n;
	struct SSTack_s *prev;
	struct SSTack_s *next;
} SSTack_t;


SSTack_t *absolute_push(SSTack_t **stack_pointer, const int n);
void build_stack(SSTack_t **stack_pointer);
void absolute_print(const SSTack_t *stack_pointer);

void wipe_stack(SSTack_t *head);
void move_to_start(SSTack_t **stack_pointer);
void move_to_end(SSTack_t **stack_pointer);

#endif
