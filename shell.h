#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/stat.h>

#define DELIMITER "\n\t"
#define MAX_ARGS 10
#define PRINT_ERROR(msg)  (perror(msg), exit(EXIT_FAILURE))

extern char **environ;
int _strlen(char *s);
void parse_input(char *input, char **args);
void handle_exit(char *input, size_t *i);
void handle_path(char **args);
void handle_env(void);
int execute_command(char **args);

#endif
