#include "monty.h"

/**
 * tokenize_line - takes a line and seperates its tokens
 * @line: line to seperate into tokens
 * @delims: delimitors to use to delimit tokens
 *
 * Return: 2D array of pointers to each word
 */
char **tokenize_line(char *line, char *delims)
{
	char **tokens = NULL;
	int word_count, word_length, n, i = 0;

	if (line == NULL || !*line)
		return (NULL);

	word_count = get_word_count(line, delims);
	if (word_count == 0)
		return (NULL);

	tokens = malloc((word_count + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	while (i < word_count)
	{
		word_length = get_word_length(line, delims);
		if (is_delimiter(*line, delims))
		{
			line = get_next_word(line, delims);
		}
		tokens[i] = malloc((word_length + 1) * sizeof(char));
		if (tokens[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(tokens[i]);
			}
			free(tokens);
			return (NULL);
		}
		n = 0;
		while (n < word_length)
		{
			tokens[i][n] = *(line + n);
			n++;
		}
		tokens[i][n] = '\0'; /* set end of line */
		line = get_next_word(line, delims);
		i++;
	}
	tokens[i] = NULL; /* last element is null for iteration */
	return (tokens);
}

/**
 * is_delimiter - checks if lineeam has delimitor char
 * @character: character in lineeam
 * @delims: Pointer to null terminated array of delimitors
 *
 * Return: 1 (success) 0 (failure)
 */

int is_delimiter(char character, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == character)
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_word_length - gets length of current word
 * @word: word we're measuring
 * @delims: delimitors to use to delimit tokens
 *
 * Return: word length of current word
 */

int get_word_length(char *word, char *delims)
{
	int length_of_word = 0, pending = 1, i = 0;

	while (*(word + i))
	{
		if (is_delimiter(word[i], delims))
			pending = 1;
		else if (pending)
			length_of_word++;

		if (length_of_word > 0 && is_delimiter(word[i], delims))
			break;
		i++;
	}
	return (length_of_word);
}

/**
 * get_word_count - gets the word count of ine
 * @line: current line
 * @delims: delimitors to use to delimit tokens
 *
 * Return: exactly what it says on the tin.
 */
int get_word_count(char *line, char *delims)
{
	int word_count = 0, pending = 1, i = 0;

	while (*(line + i))
	{
		if (is_delimiter(line[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			word_count++;
		}
		i++;
	}
	return (word_count);
}

/**
 * get_next_word - gets the next word on line
 * @line: lineing to get next word from
 * @delims: delimitors to use to delimit tokens
 *
 * Return: pointer to first char of next word
*/
char *get_next_word(char *line, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(line + i))
	{
		if (is_delimiter(line[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (line + i);
}
