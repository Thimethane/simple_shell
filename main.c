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
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			handle_exit(input, &i);
			continue;
		}
		parse_input(input, args);
		if (strcmp(args[0], "env") == 0)
		{
			handle_env();
			continue;
		}
		handle_path(args);
		ret = execute_command(args);
		if (ret < 0)
			continue;
	}
	printf("\n");
	free(input);
	return (0);
}
