#include "shell.h"

/**
 * handle_exit - exits the shell
 *
 * @input: pointer to the input string
 * @i: pointer to the input buffer size
 */
void handle_exit(char *input, size_t *i)
{
	if (strcmp(input, "exit") == 0)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
	else
	{
		*i = 0;
		free(input);
	}
}
