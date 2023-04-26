#include "shell.h"

/**
 * _getline - read a line of input from stdin
 *
 * @lineptr: pointer to the input buffer
 * @n: pointer to the size of the input buffer
 * @stream: member stream
 *
 * Return: number of characters read, -1 on failure
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t read;
	size_t len = 0;

	if (*lineptr == NULL)
	{
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	while ((read = getline(lineptr, &len, stream)) != -1)
	{
		if ((*lineptr)[read - 1] == '\n')
		{
			(*lineptr)[read - 1] = '\0';
			break;
		}
		if (*n <= len)
		{
			*n *= 2;
			*lineptr = _realloc(*lineptr, len, *n);
			if (*lineptr == NULL)
			{
				return (-1);
			}
		}
	len += read;
	}
return (len);
}
