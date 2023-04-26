#include "shell.h"

/**
 * execute_command - executes the command with the given arguments
 *
 * @args: an array of arguments for the command
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;

	handle_path(args);
	if (args[0] == NULL)
		return (0);
	pid = fork();
	if (pid < 0)
	{
		PRINT_ERROR("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		if (_strcmp(args[0], "setenv") == 0)
		{
			if (args[1] && args[2])
			{
				if (_setenv(args[1], args[2]) < 0)
					fprintf(stderr, "Error: setenv failed\n");
			}
			else
				fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		}
		else if (_strcmp(args[0], "unsetenv") == 0)
		{
			if (args[1])
			{
				if (_unsetenv(args[1]) < 0)
					fprintf(stderr, "Error: unsetenv failed\n");
			}
			else
				fprintf(stderr, "Usage: unsetenv VARIABLE\n");		}
		else
		{
			if (execvp(args[0], args) < 0)
			{
				PRINT_ERROR("execvp");
				return (-1);
			}
		}
	}
	else
		waitpid(pid, &status, 0);
	return (0);
}
