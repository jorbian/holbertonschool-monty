#!/usr/bin/env python3

class Opcode:
	function_declaration = {
        	"return_type": "void",
        	"parameters": [
                	"Sstack_t **stack",
                	"unsigned int line_number"
        	]
	}  
	def __init__(self, name, declaration=function_declaration):
		self.name = name
		self.declaration = "{} {} ({})".format(
			declaration["return_type"],
			name,
			("".join([x for x in declaration["parameters"]]))
		)

foo = Opcode("pall")

print(foo.declaration)
