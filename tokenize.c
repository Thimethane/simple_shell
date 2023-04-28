#include "shell.h"

/**
 * tokenize_input - tokenizes the input strings
 * @input: Input strings to be tokenized.
 * Return: Returns tokens of strings.
 */
char **tokenize_input(char *input)
{
	char *token_str, *quote_char;
	int token_count;
	char **tokens = malloc(MAX_TOKENS * sizeof(char *));

	if (tokens == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	token_count = 0;
	token_str = strtok(input, DELIMITER);

	while (token_str != NULL && token_count < MAX_TOKENS - 1)
	{
		if (token_str[0] == '\'' || token_str[0] == '\"')
		{
			quote_char = strchr(token_str + 1, token_str[0]);
			if (quote_char == NULL)
			{
				fprintf(stderr, "Missing closing quote\n");
				free(tokens);
				exit(EXIT_FAILURE);
			}
			quote_char[0] = '\0';
			token_str++;
			tokens[token_count] = token_str;
			token_count++;
			token_str = quote_char + 1;
		}
		else
		{
			/*quote_char = token_str[0];*/
			/*token_str++;*/
			tokens[token_count] = token_str;
			token_count++;
			token_str = strtok(NULL, DELIMITER);
		}
	}
		/*else
		{
			tokens[token_count] = token_str;
			token_count++;
			token_str = strtok(NULL, DELIMITER);
		}
	}*/
	tokens[token_count] = NULL;
	return (tokens);
}
