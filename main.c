#include "shell.h"

/**
 * main - entry point
 *
 * Return: always 0 on success
 */
int main(void)
{
	char *input;
	char *args[MAX_ARGS];
	size_t i = 0;
	ssize_t read_bytes;
	int ret;

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		read_bytes = getline(&input, &i, stdin);

		if (read_bytes == -1)
			break;/** end of file*/
		input = strtok(input, "\n");
		if (strcmp(args[0], "env") == 0)
		{
			handle_env();
			continue;
		}
		parse_input(input, args);
		handle_exit(input, &i);
		handle_path(args);
		ret = execute_command(args);
		if (ret < 0)
			continue;
	}
	printf("\n");
	free(input);
	return (0);
}
