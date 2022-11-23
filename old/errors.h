#ifndef ERRORS_H
#define ERRORS_H

#define MAX_MESSAGE_LENGTH 255

#define BAD_INPUT "USAGE: monty file\n"
#define BAD_FILE "Error: Can't open file %s\n"
#define COULDNT_MALLOC "Error: malloc failed\n"
#define BAD_INSTRUCTION "L%d: unknown instruction %s\n"
#define CANT_POP "L%d: can't pop an empty stack\n"
#define CANT_SWAP "L%d: can't swap, stack too short\n"
#define CANT_ADD "L%d: can't add, stack too short\n"

//void throw_error(char *message, ...);

#endif
