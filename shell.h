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
#define READ_SIZE 1024
#define PRINT_ERROR(msg)  (perror(msg), exit(EXIT_FAILURE))

extern char **environ;
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _atoi(char *s);
char **parse_input(char *input);
void handle_exit(char *input, size_t *i);
void handle_path(char **args);
void handle_env(char **args);
int execute_command(char **args);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
size_t _strspn(const char *s, const char *accept);
char *_strtok(char *str, const char *delim);
char *_strdup(const char *src);
int _setenv(const char *name, const char *value);
int _unsetenv(const char *name);
int cd_builtin(char **args);

#endif
