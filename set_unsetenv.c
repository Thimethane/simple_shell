#include "shell.h"

/**
 * _setenv - Initialize a new environment variable,
 *		or modify an existing one
 * @name: Name of the environment variable
 * @value: Value to assign to the environment variable
 *
 * Return: On success, 0. On failure, -1.
 */
int _setenv(const char *name, const char *value)
{
	char *val, *var;

	if (!name || !value)
		return (-1);
	var = malloc(sizeof(char) * (_strlen(name) + 2));
	if (!var)
		return (-1);
	var = _strdup(name);
	_strcat(var, "=");
	val = _strdup(value);
	if (!val)
	{
		free(var);
		return (-1);
	}
	return (setenv(var, val, 1));
}

/**
 * _unsetenv - Remove an environment variable
 * @name: Name of the environment variable to remove
 *
 * Return: On success, 0. On failure, -1.
 */
int _unsetenv(const char *name)
{
	if (!name)
		return (-1);
	return (unsetenv(name));
}
