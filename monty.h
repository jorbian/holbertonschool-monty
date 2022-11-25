#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "stack.h"
#include "errors.h"
#include "op_code.h"

#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/* PRIMARY INTERPRETER FUNCTIONS */
void free_tokens(void);
unsigned int num_of_tokens(void);
int interpret_script(FILE *file_pointer);
void set_op_tok_error(int error_code);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
void clean_up(stack_t **stack_pointer, instruct_t *chart_pointer);

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *get_int(int n);

#endif
