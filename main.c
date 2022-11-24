#include "include/monty.h"

char **op_toks = NULL;

/**
 * main - the entry point for Monty Interp
 * @argc: the count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int main(int argc, char **argv)
{
	FILE *file_pointer = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());

	file_pointer = fopen(argv[1], "r");
	if (!file_pointer)
		return (f_open_error(argv[1]));

	exit_code = interpret_script(file_pointer);

	fclose(file_pointer);

	return (exit_code);
}
