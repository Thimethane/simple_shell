#include "shell.h"

/**
 * cd_builtin - change current working directory
 * @args: array of arguments
 * Return: 1 on success, -1 on error
 */
int cd_builtin(char **args)
{
	char *new_dir;
	char *cwd = NULL;

	if (args[1] == NULL)
		new_dir = getenv("HOME");
	else if (_strcmp(args[1], "-") == 0)
		new_dir = getenv("OLDPWD");
	else
		new_dir = args[1];

	if (new_dir == NULL)
	{
		perror("cd");
		return (-1);
	}
	if (chdir(new_dir) != 0)
	{
		perror("cd");
		return (-1);
	}
	cwd = malloc((_strlen(new_dir) + 1) * sizeof(char));
	if (getcwd(cwd, _strlen(cwd) + 1) == NULL)
	{
		perror("cd");
		free(cwd);
		return (-1);
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", cwd, 1);
	free(cwd);

	return (1);
}
