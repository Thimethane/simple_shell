#include "shell.h"

/**
 * execute_command - executes the command with the given arguments
 * @command: command prompt
 * @args: an array of arguments for the command
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char *command, char **args)
{
	pid_t pid;
	int status;
	char **envp = environ;

	pid = fork();
	if (pid < 0)
	{
		PRINT_ERROR("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(command, args, envp) < 0)
		{
			PRINT_ERROR("execve");
			return (-1);
		}
	}
	else
		waitpid(pid, &status, 0);
	return (0);
}
