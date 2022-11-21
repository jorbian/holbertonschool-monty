#ifndef OP_CODES_H
#define OP_CODES_H

#include "monty.h"

/* MAKE SURE THESE ARE KEPT UPDATED AND MATCH! */
#define NUM_OF_OPS 6
#define NAME_BUFFER_SIZE 5
#define OPCODE_NAMES {"push", "pall", "pint", "pop", "swap", "nop"}
#define FUNCTIONS {push, pall, pint, pop, swap, nop}

void push(Sstack_t **stack, unsigned int line_number);
void pall(Sstack_t **stack, unsigned int line_number);
void pint(Sstack_t **stack, unsigned int line_number);
void pop(Sstack_t **stack, unsigned int line_number);
void swap(Sstack_t **stack, unsigned int line_number);
void nop(Sstack_t **stack, unsigned int line_number);

#endif
