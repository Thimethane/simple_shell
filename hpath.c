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
	
	if (args == NULL || args[0] == NULL)
	{
		PRINT_ERROR("Error: invalid arguments\n");
		return;
	}
	if (args[0][0] == '/' || args[0][0] == '.')
	{
		path = args[0];
	}
	else
	{
		path_env = getenv("PATH");
		if (path_env == NULL)
		{
			PRINT_ERROR("Error: PATH environment variable not set\n");
			free(path_env);
			return;
		}
		path_env = _strdup(path_env);
		path = _strtok(path_env, ":");
		while (path != NULL)
		{
			command = malloc(_strlen(path) + _strlen(args[0]) + 2);
			_strcat(command, path);
			_strcat(command, "/");
			_strcat(command, args[0]);
			if (stat(command, &st) == 0)
			{
				args[0] = command;
				free(path_env);
				return;
			}
			free(command);
			path = _strtok(NULL, ":");
		}
		PRINT_ERROR("Error: command not found\n");
		free(path_env);
	}
}
