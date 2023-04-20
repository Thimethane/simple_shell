#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define DELIMITER "\n\t"
#define MAX_ARGS 10
#define PRINT_ERROR(msg)  (perror(msg), exit(EXIT_FAILURE))

void parse_input(char *input, char **args);
void handle_exit(char *input, size_t *i);

#endif
