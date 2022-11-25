#!/usr/bin/env python3

import re
import os

file_structure = {
    "include": "((.*).h$)",
    "opcode": "(^op_code(.*).c)",
    "bytecodes": "^\d{2}.m",
    "src": "(^((?!op_code).)*.c)",
    "scripts": "((.*)(.sh|.py)$)"
}

folder_names = list(file_structure.keys())

for folder in folder_names:
    os.makedirs(folder, exist_ok=True)

with os.scandir() as home_directory:

    for file in home_directory:
        
        if file.is_dir():
            continue

        for folder_name, rule in file_structure.items():

            if re.match(rule, file.name):
                new_path = f'{folder_name}/{file.name}'

                if not os.path.exists(new_path):
                    os.rename(file.path, new_path)
                else:
                    continue

                continue