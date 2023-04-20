#include "shell.h"

/**
 * handle_env - prints the current environment
 */
void handle_env(void)
{
	int i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
