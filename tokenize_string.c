#include <stdlib.h>

char **stringtow(char *string, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *string, char *delims);
int get_word_count(char *string, char *delims);
char *get_next_word(char *string, char *delims);

/**
* stringtow - takes a stringing and seperates its words
* @string: stringing to seperate into words
* @delims: delimitors to use to delimit words
* 
* Return: 2D array of pointers to each word
*/
char **stringtow(char *string, char *delims)
{
	char **words = NULL;
	int word_count, word_length, n, i = 0;

	if (string == NULL || !*string)
		return (NULL);

	word_count = get_word_count(string, delims);
	if (word_count == 0)
		return (NULL);

	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	do {
		word_length = get_word_length(string, delims);
		if (is_delim(*string, delims))
			string = get_next_word(string, delims);

		words[i] = malloc((word_length + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < word_length)
		{
			words[i][n] = *(string + n);
			n++;
		}
		words[i][n] = '\0'; /* set end of string */
		string = get_next_word(string, delims);
		
	} while (i++ < word_count); 

	words[i] = NULL; /* last element is null for iteration */
	return (words);
}

/**
 * is_delim - checks if stringeam has delimitor char
 * @ch: character in stringeam
 * @delims: Pointer to null terminated array of delimitors
 *
 * Return: 1 (success) 0 (failure)
 */
int is_delim(char ch, char *delims)
{
	int i = 0;

	do {
		if (delims[i] == ch)
			return (1);
	} while (delims[i++]);
	return (0);
}

/**
 * get_word_length - gets the word length of cur word in string
 * @string: stringing to get word length from current word
 * @string: stringing to get word length from current word
 * @delims: delimitors to use to delimit words
 *
 * Return: word length of current word
 */
int get_word_length(char *string, char *delims)
{
	int word_length = 0, pending = 1, i = 0;

	do {
		if (is_delim(string[i], delims))
			pending = 1;
		else if (pending)
			word_length++;

		if (word_length > 0 && is_delim(string[i], delims))
			break;
	} while ((*(string + i++)));

	return (word_length);
}

/**
 * get_word_count - gets the word count of a stringing
 *
 * @string: stringing to get word count from
 * @delims: delimitors to use to delimit words
 *
 * Return: the word count of the stringing
 */

int get_word_count(char *string, char *delims)
{
	int word_count = 0, pending = 1, i = 0;

	do {
		if (is_delim(string[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			word_count++;
		}
	} while ((*(string + i++)));

	return (word_count);
}

/**
 * get_next_word - gets the next word in a stringing
 * @string: stringing to get next word from
 * @delims: delimitors to use to delimit words
 * Return: pointer to first char of next word
 */

char *get_next_word(char *string, char *delims)
{
	int pending = 0;
	int i = 0;

	do {
		if (is_delim(string[i], delims))
			pending = 1;
		else if (pending)
			break;
	} while ((*(string + i++)));

	return (string + i);
}
