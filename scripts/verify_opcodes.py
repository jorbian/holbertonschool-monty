#!/usr/bin/env python3

import os
import re

boiler_plate_header = """
#ifndef guard
#define guard

#include "monty.h

/* MAKE SURE THESE ARE KEPT UPDATED AND MATCH! */
#define NUM_OF_OPS num_of_ops
#define NAME_BUFFER_SIZE buffer_size
#define OPCODE_NAMES names
#define FUNCTIONS func_pointers

typedef struct instruct_s
{
        char *opcode;
        void (*f)(stack_t **stack_pointer, unsigned int line_number);
        struct instruct_s *prev;
        struct instruct_s *next;
} instruct_t;

declarations
#endif
"""

class OpcodeFolder:

    default_folder = "/home/boller/Documents/GitHub/holbertonschool-monty/opcode"
    defailt_search_pattern = {
        "filename": "(^op_code(.*).c)",
        "opcode": "(?<=op_code_)(.*)(?=.c)",
        "declaration": "(void(.*)\(stack_t \*\*(.*), unsigned int(.*)\))"
    }

    def __init__(self, folder=default_folder):
        self.folder = folder
        self.op_codes = []

        self.inventory_folder()


    def inventory_folder(self, patterns=defailt_search_pattern):

        with os.scandir(self.folder) as op_code_folder:

            for source_file in op_code_folder:

                if not re.match(patterns["filename"], source_file.name):
                    continue

                with open(source_file.path) as current_file:

                    code = current_file.read()
                    declaration = (re.search(patterns["declaration"], code)).group()

                    (self.op_codes).append(
                        {
                            "name": (re.search(patterns["opcode"], source_file.name)).group(),
                            "declaration": declaration
                        }
                    )


class OpcodeHeader:

    def __init__(self, boilerplate, name="op_code.h", path="", code=""):
        self.name = name
        self.path = path
        self.current_code = code
        self.boilerplate = boilerplate

        if (not path) or (not os.path.exists(path)):
            self.make_new_header(code=self.current_code)


    def make_new_header(self, folder=OpcodeFolder(), code=""):

        if (not code):
            self.generate_preprocessor_code(folder)
            code = self.current_code

        with open(self.name, "w") as header_file:
            header_file.write(code)


    def generate_preprocessor_code(self, folder=OpcodeFolder()):
        #MAKES SURE TO SLICE OFF LAST TWO CHARACTERS
        def join_and_bracket(x):
            return (f'{{{"".join(x)[:-2]}}}')

        opcode_names = [opcode["name"] for opcode in folder.op_codes]
        declarations = [opcode["declaration"] for opcode in folder.op_codes]

        things_to_put_in_header = {
            "guard": ((self.name).upper()).replace(".","_"),
            "num_of_ops": str(len(opcode_names)),
            "buffer_size": str(max([len(x) for x in opcode_names]) + 1),
            "names": join_and_bracket([f'"{name}", ' for name in opcode_names]),
            "func_pointers": join_and_bracket([f"{name}, " for name in opcode_names]),
            "declarations": ("\n".join([f"{func};" for func in declarations])) + "\n"
        }
        for blank, info in things_to_put_in_header.items():
            self.current_code = (self.boilerplate).replace(blank, info)



OpcodeHeader(boiler_plate_header)