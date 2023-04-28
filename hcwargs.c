#include "shell.h"

/**
 * handle_command_with_arguments - handle commands with their arguments
 * @args: Input command
 *
 * Return: No return value.
 */
void handle_command_with_arguments(char **args)
{
	pid_t pid;
	int status;
	char *token, *env_path = getenv("PATH");
	char full_path[PATH_MAX];

	if (strcmp(args[0], "exit") == 0)
		exit(0);

	pid = fork();
	if (pid == 0)
	{
		if (args[0][0] == '/')
		{
			execve(args[0], args, NULL);
		}
		else
		{
			token = strtok(env_path, ":");
			while (token != NULL)
			{
				/**path = malloc(_strlen(token) + _strlen(args[0]) + 2);*/
				sprintf(full_path, "%s/%s", token, args[0]);
				execve(full_path, args, NULL);
				/**free(path);*/
				token = strtok(NULL, ":");
			}
		}
		printf("Command not found: %s\n", args[0]);
		exit(1);
	}
	else if (pid < 0)
	{
		perror("Fork failed");
	}
	else
	{
		do

		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/**
 * free_args - it releases the allocated memory arguments
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
