#include "include/monty.h"

int main(int argc, char *argv[])
{
    CommandParser_t *parser = NULL;
    ScriptBuffer_t *script = NULL;
    int error_status = (argc == 2);

    if (error_status)
        return (throw_error(BAD_INPUT, 0, ""));

    error_status = create_command_parser(&parser);
    if (error_status)
        return (error_status);

    error_status = create_script_buffer(&script);
    if (error_status)
        return (error_status);
}