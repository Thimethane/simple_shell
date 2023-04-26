#include "shell.h"

/**
 * main - entry point
 *
 * Return: always 0 on success
 */
int main(void)
{
	char *input = NULL;
	char *args[MAX_ARGS];
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
		input[_strcspn(input, "\n")] = '\0';
		if (_strcmp(input, "exit") == 0 || _strncmp(input, "exit ", 5) == 0)
		{
			handle_exit(input, &len);
			continue;
		}
		parse_input(input, args);
		if (_strcmp(args[0], "env") == 0)
		{
			handle_env();
			continue;
		}
		if (handle_path(args))
		{
			ret = execute_command(args);
			if (ret < 0)
				continue;
			free(args[0]);
		}
	}
	printf("\n");
	free(input);

	return (0);
}
