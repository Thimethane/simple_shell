#include "shell.h"

/**
 * handle_EOF - exits the shell when EOF is encountered
 *
 * @input: pointer to the input string
 */
void handle_EOF(char *input)
{
	if (feof(stdin))
	{
		if (isatty(STDIN_FILENO))
			printf("\n");
		free(input);
		exit(EXIT_SUCCESS);
	}
}
