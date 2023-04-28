#include "shell.h"

/**
 * handle_exit - exits the shell
 *
 * @input: pointer to the input string
 * @i: pointer to the input buffer size
 */
void handle_exit(char *input, size_t *i)
{
	int status;

	if (strcmp(input, "exit") == 0)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
	else if (strncmp(input, "exit ", 5) == 0)
	{
		status = atoi(input + 5);
		free(input);
		exit(status);
	}
	else
	{
		*i = 0;
		free(input);
	}
}
