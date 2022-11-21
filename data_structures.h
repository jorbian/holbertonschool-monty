#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

/**
 * struct Sstack_s - representation of a stack/que as doubly linked list
 * @n: integer
 * @prev: previous element of the stack (or queue)
 * @next: next element of the stack/que
 *
 * Description: doubly linked list node structure for stack/que
 */
typedef struct Sstack_s
{
	int n;
	struct Sstack_s *prev;
	struct Sstack_s *next;
} Sstack_t;

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
        void (*f)(Sstack_t **stack, unsigned int line_number);
        struct instruct_s *prev;
        struct instruct_s *next;
} instruct_t;

#endif
