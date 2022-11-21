#ifndef OP_CODE_H
#define OP_CODE_H

#include ""
/* MAKE SURE THESE ARE KEPT UPDATED AND MATCH! */
#define NUM_OF_OPS 6
#define NAME_BUFFER_SIZE 5
#define OPCODE_NAMES {"push", "pall", "pint", "pop", "swap", "nop"}
#define FUNCTIONS {push, pall, pint, pop, swap, nop}

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruct_s
{
        char *opcode;
        void (*f)(dlistint_t **stack, unsigned int line_number);
        struct instruct_s *prev;
        struct instruct_s *next;
} instruct_t;

void push(dlistint_t  **stack, unsigned int line_number);
void pall(dlistint_t  **stack, unsigned int line_number);
void pint(dlistint_t  **stack, unsigned int line_number);
void pop(dlistint_t  **stack, unsigned int line_number);
void swap(dlistint_t  **stack, unsigned int line_number);
void nop(dlistint_t  **stack, unsigned int line_number);

#endif
