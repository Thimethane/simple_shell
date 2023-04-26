#include "shell.h"

/**
 * parse_input - parses the input into an array of strings
 * @input: input string to parse
 * Return: 0 (Success)
 */
char **parse_input(char *input)
{
	char *delim = " \t\r\n\a";
	char *token;
	char **tokens = malloc((_strlen(input) + 1) * sizeof(char *));
	int i = 0;

	if (tokens == NULL)
		exit(EXIT_FAILURE);
	if (input != NULL)
		token = strtok_r(input, delim, &input);
	while (token != NULL)
	{
		if (i >= _strlen(token) - 1)
		{
			tokens[i++] = token;
			if (tokens == NULL)
				exit(EXIT_FAILURE);
		}
		token = strtok_r(NULL, delim, &input);
	}
	tokens[i] = NULL;
	return (tokens);
}
