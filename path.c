#include "shell.h"
/**
 * handle_path - checks the path
 * @args: An array of arguments
 *
 * Return: 1 if the command is a path command, 0 otherwise
 */
int handle_path(char **args)
{
        struct stat st;
        char *path, *path_env, *command;
        int ret;
        size_t command_len;

        if (_strchr(args[0], '/') != NULL && stat(args[0], &st) == 0)
                return (1);
        path_env = getenv("PATH");
        if (path_env == NULL)
        {
                PRINT_ERROR("Error: PATH environment variable not set\n");
                return (0);
        }
        path = strtok(path_env, ":");
        while (path != NULL)
        {
                command_len = _strlen(path) + _strlen(args[0]) + 2;
                command = malloc(command_len);
                if (command == NULL)
                {
                        PRINT_ERROR("Error: malloc failed\n");
                        free(path_env);
                        return (0);
                }
                ret = snprintf(command, command_len, "%s/%s", path, args[0]);
                if (ret < 0 || (size_t)ret >= command_len)
                {
                        PRINT_ERROR("Error: snprintf failed\n");
                        free(command);
                        free(path_env);
                        return (0);
                }
                if (stat(command, &st) == 0)
                {
                        args[0] = command;
                        free(path_env);
                        return (1);
                }
                free(command);
                path = strtok(NULL, ":");
        }
        PRINT_ERROR("Error: command not found\n");
        return (0);
}
