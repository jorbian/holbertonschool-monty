def join_and_bracket(x):
    return (f'{"".join(x)[:-1]}')

name = "op_code.h"
op_codes = ["push", "pall", "pint", "pop", "swap", "nop"]

opcode_names = [opcode["name"] for opcode in op_codes]
declarations = [opcode["declaration"] for opcode in op_codes]

things_to_put_in_header = ({
    "guard": ((name).upper()).replace(".","_"),
    "number": len(opcode_names),
    "buffer_size": str(max([len(x) for x in opcode_names]) + 1),
    "names": join_and_bracket([f'"{name}",' for name in opcode_names]),
    "func_pointers": join_and_bracket([f"{name}," for name in opcode_names]),
    "declarations": "\n".join([f"{func};" for func in declarations])
})
