#ifndef MONTY_H
#define MONTY_H

/* STANDARD LIBRARY HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <ctype.h>

#include "stack.h"
#include "op_code.h"

#define DELIMS "\t\n "
#define EXTENSION ".m"

typedef struct buffer_s
{
	char *line;
	struct buffer_s *next;
    struct buffer_s *prev; 
} buffer_t;

void load_file(buffer_t **buffer_pointer, char *filename);
buffer_t *add_line(buffer_t **buffer_pointer, char *line);
void wipe_buffer(buffer_t *buffer_pointer);
void find_begining_of_file(buffer_t **buffer_pointer);
int is_usable_input(char *filename);

int is_number(const char *s);
void begining_of_chart(instruct_t **chart_pointer);
instruct_t *create_instruction(
	instruct_t **last_entry,
	const char *next_opcode,
	void (*next_fp)(SSTack_t **, unsigned int)
);
void fill_chart_in(instruct_t **top_of_chart);

#endif 
