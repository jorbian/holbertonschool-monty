#ifndef TEST_H
#define TEST_H

#include <stdlib.h>
#include <stdio.h>

#define TEST_NAMES {"add", "sub", "div"}
#define TEST_FUNCTIONS {test_function1, test_function2, test_function3}

typedef void (*fp)(int, int);

typedef struct instruct_s
{
        char *opcode;
        void (*fp)(int, int);
        struct instruct_s *next;
} instruct_t;

void test_function1(int x, int y);
void test_function2(int x, int y);
void test_function3(int x, int y);

instruct_t *create_instruction(instruct_t **top, const char *name, fp pointer);

#endif 
