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
#include <limits.h>
#include <sys/stat.h>

#define DELIMITER " \t \r \n \a ; && ||"
#define MAX_ARGS 10
#define READ_SIZE 1024
#define MAX_TOKENS 100
#define MAX_BUFFER 1024
#define PRINT_ERROR(msg)  (perror(msg), exit(EXIT_FAILURE))

extern char **environ;

int _strlen(char *s);
char *_strdup(const char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _atoi(char *s);
char **tokenize_input(char *input);
int execute_command(char *command, char **args);
void handle_command_with_arguments(char **tokens);
void handle_env(void);
void handle_exit(char *input, size_t *i);
void free_args(char **tokens);
void handle_EOF(char *input);
char *shell_getline(void);
int copy_and_execute(char *src_file, char *dest_file, char **args);
#endif
