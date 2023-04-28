#include "shell.h"

/**
 * main - entry point
 *
 * Return: always 0 on success
 */
int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	size_t input_length = 0;
	char **args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		fflush(stdout);

		if (getline(&input, &input_size, stdin) == -1)
		{
			/*printf("\n");*/
			break;
		}
		input_length = _strlen(input);
		if (input_length > 0 && input[input_length - 1] == '\n')
			input[input_length - 1] = '\0';
		input_size = input_length + 1;
		if (strcmp(input, "exit") == 0 || strncmp(input, "exit ", 5) == 0)
                {
                        handle_exit(input, &input_length);
                        continue;
		}

		args = tokenize_input(input);
		if (strcmp(args[0], "env") == 0)
		{
			handle_env();
			/*free_args(args);*/
			continue;
		}
		/**args = split_line(input);*/
		if (args[0] != NULL)
		{
			handle_command_with_arguments(args);
			/**free_args(args);*/
		}
	}
	free(input);
	return (0);
}
