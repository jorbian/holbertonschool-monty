#ifndef ERRORS_H
#define ERRORS_H

/* DEFINITIONS OF ERRORS AND THE ERROR HANDLIJG ROUTINE(S) */
#define BAD_INPUT "USAGE: monty file\n"
#define BAD_FILE "Error: Can't open file %s\n"
#define COULDNT_MALLOC "Error: malloc failed\n"
#define BAD_INSTRUCTION "L%d: unknown instruction %s\n"
#define CANT_POP "L%d: can't pop an empty stack\n"
#define CANT_SWAP "L%d: can't swap, stack too short\n"
#define CANT_ADD "L%d: can't add, stack too short\n"

/* ERROR MESSAGES & ERROR CODES */
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);

#endif
