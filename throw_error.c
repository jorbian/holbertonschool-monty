#include "monty.h"
#include "errors.h"

/**
 * throw_error - prints relevant error message
 * @message: the specific error message
 * @line: line number (if any) -- 0 otherwise
 * @string: additional string (if any) -- "" otherwise
 * 
 * Return: always returns EXIT_FAILURE
*/
int throw_error(char *message, int line, char *string)
{
	if (!line && !string)
		fprintf(stderr, message, "");
	else if (line && !string)
		fprintf(stderr, message, line);
	else if (!line && string)
		fprintf(stderr, message, string);
	else
		fprintf(stderr, message, line, string);

	return (EXIT_FAILURE);
}

/**
 * set_op_tok_error - Sets last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_tok_error(int error_code)
{
	int toks_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = num_of_tokens();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		throw_error(COULDNT_MALLOC, 0, "");
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		throw_error(COULDNT_MALLOC, 0, "");
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
