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

	if (_strcmp(input, "exit") == 0)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
	else if (_strncmp(input, "exit ", 5) == 0)
	{
		status = _atoi(input + 5);
		free(input);
		if (status < 0)
			status = abs(status);
		exit(status);
	}
	else
	{
		*i = 0;
		free(input);
	}
}
