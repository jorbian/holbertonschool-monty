#ifndef STRINGDATA_H
#define STRINGDATA_H

#include <stdlib.h>

/**
 * struct StringBuffer_s - Doubly linked list of strings 
 * @string: string store in buffer (either a whole line or command token)
 * @prev_line: points to previous line.
 * @next_line: points to next line.
 * 
 * Description: doubly linked list used to represent lines of file or
 * command tokens.
 */
typedef struct StringBuffer_s
{
		char *contents;
		struct StringBuffer_s *next;
		struct StringBuffer_s *prev;
} StringBuffer_t;

/**
 * struct ScriptBuffer_s - centralized location all we need to read script
 * @curr_line: pointer to the current line as LineBuffer_s
 * @curr_line_num: line number of current line being pointed to
 *
 * Description: doubly linked list nested inside ScriptBuffer --
 * whose function is to contain pointers to de faccto object methods.
 */
typedef struct ScriptBuffer_s
{
		struct StringBuffer *curr_line;
		int curr_line_num;
		int error_tripped;
} ScriptBuffer_t;

/* FUNCTIONS USED TO CREATE AND MANAGE STRING BUFFERS, LINE, TOK 'AND OTHER' */
StringBuffer_t *add_to_end(StringBuffer_t **top_node, const char *new_str);
StringBuffer_t *add(StringBuffer_t **top_node, const char *new_str);
char *pop(StringBuffer_t **top_node);
void check(const StringBuffer_t *current_node);
void free_stringbuff(StringBuffer_t *current_node);

/* METHODS (I.E. FUNCTIONS) FOR CREATING AND USING SCRIPTBUFFER */
int create_script_buffer(ScriptBuffer_t **self);
void load_script_from_file(ScriptBuffer_t **self, char *file_name);
void list_script(ScriptBuffer_t **self);
void clear_script(ScriptBuffer_t **self);
char *pop_line(ScriptBuffer_t **self);
void free_scriptbuffer(ScriptBuffer_t **self);

#endif

