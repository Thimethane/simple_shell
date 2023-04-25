#include "shell.h"

/**
 * parse_input - parses the input into an array of strings
 * @input: input string to parse
 * @args: array of strings to store parsed input
 */
void parse_input(char *input, char **args)
{
	char *token;
	int i = 0;

	token = strtok(input, DELIMITER);

	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, DELIMITER);
	}
	args[i] = NULL;
}
