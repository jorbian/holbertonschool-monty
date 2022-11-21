#!/usr/bin/env python2.7

def find_longest_len(list_of_strings):
	return (max([len(string) for string in list_of_strings]) + 1)

strings = ["push", "pall", "pint", "pop", "swap", "nop"]

print(find_longest_len(strings))

