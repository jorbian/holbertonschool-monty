#include "lists.h"
#include <strings.h>

int main()
{
	char *input_buffer;
	take_user_input(input_buffer);

	printf("%s",input_buffer);
}

void take_user_input(char *input_buffer)
{
	fgets(input_buffer, 8, stdin);)
}
