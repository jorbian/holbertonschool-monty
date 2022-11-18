#ifndef OPCODES_H
#define OPCODES_H

#include "monty.h"

/* MAKE SURE ALL OF THIS INFORMATION IS UP TO DATE BEFORE COMPILING */
#define NUM_OF_OPCODES 2
#define NAME_BUFFERSIZE 5 
#define OPCODE_NAMES {"push", "pall"}
#define NNEDS_ARG {1, 0}
#define FUNCTION_POINTERS {}
 
/**
 * struct opcode_entry_s  - Node of a hash table
 * @key: The key, string
 * @instruction: Opcode for key
 * @requiress_pos_arg: either 0 (False) or NOT 0 (True)
 * @next: A pointer to the next node of the List
 */
typedef struct opcode_entry_s
{
     char *key;
     instruction_t instruction;
     int nneds_arg; 
     struct opcode_entry_s *next;
} opcode_entry_t;

/**
 * struct opcode_chart_s - 
 * @size: The size of the array
 * @entries: stored in array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct opcode_chart_s
{
     unsigned long int size;
     opcode_entry_t **entries;
} opcode_chart_t;

#endif
