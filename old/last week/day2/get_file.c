#include "monty.h"

#define MAX_LINE_LENGTH 30
#define MAX_NUM_LINES 30

int main(int argc, char *argv[])
{
	char[MAX_NUM_LINES][MAX_LINE_LENGTH] lines;

	return 0;
}

char **read_lines_of_file(char *filename)
{
	char **lines_of_file[MAX_NUM_LINES][MAX_LINE_LENGTH];
	char *individual_line;
	FILE *file_pointer;

	file_pointer = fopen(filename, "r");
	while (fgets(str, MAX_NUM_LINES, fp))
}
