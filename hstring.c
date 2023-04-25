#include "shell.h"

/**
 * execute_command - executes the command with the given arguments
 *
 * @args: an array of arguments for the command
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		PRINT_ERROR("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) < 0)
		{
			PRINT_ERROR("execvp");
			return (-1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (0);
}

/**
 * _strlen - returns length of the string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
 * _strcmp - compares two strings
 * @s1:string 1
 * @s2:string 2
 * Return:strings
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * *_strcat - concatenates two strings
 * @dest:destination
 * @src:source
 * Return:pointer
 */
char *_strcat(char *dest, char *src)
{
	char *dest_end = dest;

	while (*dest_end != '\0')
	{
		dest_end++;
	}

	while (*src != '\0')
	{
		*dest_end = *src;
		dest_end++;
		src++;
	}

	*dest_end = '\0';
	return (dest);
}
