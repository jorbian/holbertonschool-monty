#include "include/monty.h"

/**
* main - the entry ppint for the program
* @argc: number of arguments passed to program (should be two)
* @argv: the arguments (should be {'./monty', $filename}
*
* Return: 0
*/
int main (int argc, char *argv[])
{
	if (argc != 2)
		throw_error(WRONG_INPUT);
	
	interpret_file(
		get_file(argv[1])
	);	

	return (0);
}

