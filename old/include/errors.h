#ifndef ERRORS_H
#define ERRORS_H

/* list of possible error message designed to be expanable */
#define WRONG_INPUT "USAGE: monty file\n"
#define BAD_FILE "Error: Can't open file\n"
#define BAD_COMMAND "L%d: unknown instruction %s\n"
#define COULDNT_MALLOC "Error: malloc failed\n"

#define EXTENSION ".m"

/* string buffers related to error handling or testing */
#define MIN_INPUT_LENGTH 4
#define MAX_ERROR_LENGTH 32
#define MAX_LINE_SIZE  255

void throw_error(char *message);

#endif
