#ifndef MONTY_H
#define MONTY_H

/* PROJECT SPECIFIC HEADERS */
#include "data_structures.h"
#include "op_code.h"
#include "errors.h"

/* STANDARD LIBRARY HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* FILE BUFFER LENGTHS */
#define MAX_LINE_LENGTH 255
#define MAX_NUM_LINES 50
#define LID -2147483647

void load_file(
    char (*file_buffer)[MAX_NUM_LINES],
    char *filename
);
void interpret_file(char (*file_buffer)[MAX_NUM_LINES]);
int find_opcode(instruct_t **chart, const char *line_buffer);
void back_to_top_of_chart(instruct_t **chart);

/* CREATING AND TESTING THE CHART TO LOOK UP INSTRUCTIONS */
void fill_chart_in(instruct_t **top_of_chart);
instruct_t *create_instruction(
	instruct_t **last_entry,
	const char *next_opcode,
	void (*next_fp)(Sstack_t **, unsigned int)
);


#endif 
