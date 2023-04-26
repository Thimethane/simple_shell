#include "shell.h"

/**
 * _strtok - Tokenizes input string
 * @str: Input string
 * @delim: A delimeter to be used
 *
 * Return: 0 on Sucess
 */
char *_strtok(char *str, const char *delim)
{
	static char *last_token;
	char *token;
	if (str != NULL)
		last_token = str;
	if (last_token == NULL)
		return (NULL);
	token = last_token;
	while (*last_token && !strchr(delim, *last_token))
		last_token++;
	if (*last_token)
		*last_token++ = '\0';
	return (token);
}
