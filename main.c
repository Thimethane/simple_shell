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
	pid_t pid;
	int status;

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		read_bytes = getline(&input, &i, stdin);

		if (read_bytes == -1)
			break;/** end of file*/
		input = strtok(input, "\n");

		parse_input(input, args);
		if (strcmp(args[0], "exit") == 0)
		{
			handle_exit(input, &i);
			continue;
		}
		pid = fork();
		if (pid < 0)
			PRINT_ERROR("fork");
		else if (pid == 0)
		{
			if (execvp(args[0], args) < 0)
				PRINT_ERROR("execvp");
		}
		else
			waitpid(pid, &status, 0);
	}
	printf("\n");
	free(input);
	return (0);
}
