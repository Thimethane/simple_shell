#include "shell.h"

/**
 * tokenize_input - tokenizes the input strings
 * @input: Input strings to be tokenized.
 * Return: Returns tokens of strings.
 */
char **tokenize_input(char *input)
{
	char **tokens = (char **)malloc(MAX_TOKENS * sizeof(char *));
	char **token;
	size_t num_tokens = 0;

	if (tokens == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(1);
	}
	*tokens = strtok(input, DELIMETER);
	token = tokens;
	while (token != NULL && num_tokens < MAX_TOKENS)
	{
		token++;
		*token = strtok(NULL, DELIMETER);
		num_tokens++;
	}
	*token = NULL;
	return (tokens);
}
