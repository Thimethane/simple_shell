#include "shell.h"

/**
 * main - entry point
 *
 * Return: always 0 on success
 */
int main(void)
{
	char *input = NULL;
	char **args;
	size_t len = 0;
	ssize_t read_bytes;
	int ret;

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		read_bytes = _getline(&input, &len, stdin);

		if (read_bytes == -1)
			break;/** end of file*/
		input[strcspn(input, "\n")] = '\0';
		if (_strcmp(input, "exit") == 0 || strncmp(input, "exit ", 5) == 0)
		{
			handle_exit(input, &len);
			continue;
		}
		args = parse_input(input);
		if (_strcmp(args[0], ("env")) == 0)
		{
			handle_env(args);
			continue;
		}
		if (_strcmp(args[0], "cd") == 0)
		{
			cd_builtin(args);
			continue;
		}
		ret = execute_command(args);
		if (ret < 0)
			continue;
	}
	printf("\n");
	free(args);
	free(input);
	return (0);
}
