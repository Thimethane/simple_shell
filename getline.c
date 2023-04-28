#include "shell.h"

/**
 * shell_getline - read a line of input from stdin
 *
 * Return: a pointer to the input buffer on success, NULL on failure
 */
char *shell_getline(void)
{
	char *input;
	static char buffer[READ_SIZE], *buf_pos = buffer;
	static size_t buf_size = READ_SIZE;
	static ssize_t bytes_read;
	size_t input_len = 0;

	if (bytes_read == 0)
	{
		buf_pos = buffer;
		bytes_read = read(STDIN_FILENO, buffer, buf_size);
		if (bytes_read == -1 || bytes_read == 0)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			return (NULL);
		}
	}
	while (*buf_pos != '\n' && bytes_read > 0)
	{
		input_len++;
		buf_pos++;
		if (--bytes_read == 0)
		{
			buf_pos = buffer;
			bytes_read = read(STDIN_FILENO, buffer, buf_size);
			if (bytes_read == -1 || bytes_read == 0)
			{
				if (isatty(STDIN_FILENO))
					printf("\n");
				return (NULL);
			}
		}
	}
	input = malloc(input_len + 1);
	memcpy(input, buf_pos - input_len, input_len);
	input[input_len] = '\0';
	buf_pos++;
	bytes_read--;
	return (input);
}
