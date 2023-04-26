#include "shell.h"

/**
 * handle_env - prints the current environment
 */
void handle_env(char **args)
{
	int i = 0, j = 0;

	for (i = 0; args[i] != NULL; i++)
	{
		if (strcmp(args[i], "env") == 0 ||
			strcmp(args[i], "environ") == 0 ||
			strcmp(args[i], "printenv") == 0)
		{
			while (environ[i] != NULL)
			{
				printf("%s\n", environ[i]);
				j++;
			}
			break;
			
		}
	}
}
