#ifndef MONTY_H
#define MONTY_H

/* STANDARD LIBRARY HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>

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

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);


#endif 
