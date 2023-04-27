#include "shell.h"

/**
 * handle_command_with_arguments - handle commands with their arguments
 * 					and PATH at the same time
 *
 * @tokens: Input command
 *
 * Return: No return value.
 */
void handle_command_with_arguments(char **tokens)
{
	char *path = getenv("PATH");
	char *path_token;
	size_t command_path_length, i;
	char *command_path;
	char *path_copy;
	char *command = tokens[0];
	char **args;

	args = malloc((MAX_TOKENS + 1) * sizeof(char *));
	if (path == NULL)
	{
		printf("Error: PATH not found.\n");
		return;
	}
	path_copy = _strdup(path);
	if ((args == NULL) || (path_copy == NULL))
	{
		printf("Error: Memory allocation failed.\n");
		return;
	}
	for (i = 0; tokens[i] != NULL && i < MAX_TOKENS; i++)
		args[i] = tokens[i];
	args[i] = NULL;
	path_token = strtok(path_copy, ":");
	while (path_token != NULL)
	{
		command_path_length = _strlen(path_token) + _strlen(command) + 2;
		command_path = malloc(command_path_length);
		if (command_path == NULL)
		{
			printf("Error: Memory allocation failed.\n");
			free(path_copy);
			return;
		}
		snprintf(command_path, command_path_length, "%s/%s", path_token, command);
		if (access(command_path, X_OK) == 0)
		{
			execute_command(command_path, args);
			return;
		}
		path_token = strtok(NULL, ":");
	}
	printf("Command not found: %s\n", command);
	free(command_path);
	free(path_copy);
	free(args);
}

/**
 * free_args: it releases the allocated memory arguments
 *
 * @tokens: tokens of input command
 *
 * Return: No return value
 */
void free_args(char **tokens)
{
	char **token = tokens;

	while (*token != NULL)
	{
		free(*token);
		token++;
	}
	free(tokens);
}
