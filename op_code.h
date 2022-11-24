#ifndef OPCODE_H
#define OPCODE_H

#include "monty.h"

/* MAKE SURE THESE ARE KEPT UPDATED AND MATCH! */
#define NUM_OF_OPS 6
#define NAME_BUFFER_SIZE 5
#define OPCODE_NAMES {"push", "pall", "pint", "pop", "swap", "nop"}
#define FUNCTIONS {push, pall, pint, pop, swap, nop}

/**
 * struct instruct_s - doubly-linked list of all the opcodes
 * @opcode: the opcode
 * @f: function to handle the opcode
 * @prev: previous opccode on list
 * @next: next opcode on list
 * Description: 
 */
typedef struct instruct_s
{
        char *opcode;
        void (*f)(stack_t **stack_pointer, unsigned int line_number);
        struct instruct_s *next;
        struct instruct_s *prev;
} instruct_t;

/* FUNCTIONS TO BUILD THE LIST THE OPCODES ARE STORED IN */
int fill_chart_in(instruct_t **top_of_chart);
void erasse_chart(instruct_t *chart_pointer);
instruct_t *create_instruction(
	instruct_t **last_entry,
	const char *next_opcode,
	void (*next_fp)(stack_t **, unsigned int)
);
void (*look_up_instruction(instruct_t **chart_pointer, char *token))(stack_t**, unsigned int);

/* FUNCTIONS DEFINING THE BEHAVIOUR OF SPECIFIC OPCODES */
void push(stack_t **stack_pointer, unsigned int line_number);
void pall(stack_t **stack_pointer, unsigned int line_number);
void pint(stack_t **stack_pointer, unsigned int line_number);
void pop(stack_t **stack_pointer, unsigned int line_number);
void swap(stack_t **stack_pointer, unsigned int line_number);
void add(stack_t **stack_pointer, unsigned int line_number);
void nop(stack_t **stack_pointer, unsigned int line_number);

#endif