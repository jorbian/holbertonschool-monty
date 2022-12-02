#include "monty.h"

int main(int argc, char *argv[])
{
    ScriptBuffer_t *script = NULL;
    int error_status = (argc == 2);

    if (error_status)
        return (throw_error(BAD_INPUT, 0, ""));

    error_status = create_script_buffer(&script);
    if (error_status)
        return (error_status);

    load_script_from_file(&script, argv[1]);
    error_status = script->error_tripped;
    if (error_status)
        return (error_status);

    while (script->curr_line != NULL)
        printf("LINE[%d]: %s", script->curr_line_num, pop_line(&script));
        
    free_scriptbuffer(&script);

    return (error_status);
}
