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

#define DELIMETER "\n\t"
#define MAX_ARGS 10
#define READ_SIZE 1024
#define MAX_TOKENS 64
#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM " \t\r\n\a"
#define PRINT_ERROR(msg)  (perror(msg), exit(EXIT_FAILURE))

extern char **environ;

int _strlen(char *s);
char *_strdup(const char *src);
char **tokenize_input(char *input);
int execute_command(char *command, char **args);
void handle_command_with_arguments(char **tokens);
void free_args(char **tokens);

#endif
