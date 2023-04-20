#include "shell.h"

/**
 * handle_path - checks the path
 * @args: An array of arguments
 *
 * Return: None
 */
void handle_path(char **args)
{
	char *path, *command, *path_env;
	struct stat st;
	if (args[0][0] == '/' || args[0][0] == '.')
	{
		path = args[0];
	}
	else
	{
		path_env = getenv("PATH");
		if (path_env == NULL)
		{
			printf("Error: PATH environment variable not set\n");
			return;
		}
		path = strtok(path_env, ":");
		while (path != NULL)
		{
			command = malloc(strlen(path) + strlen(args[0]) + 2);
			sprintf(command, "%s/%s", path, args[0]);
			if (stat(command, &st) == 0)
			{
				args[0] = command;
				return;
			}
			free(command);
			path = strtok(NULL, ":");
		}
		printf("Error: command not found\n");
		return;
	}
}
