#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

extern char **environ;  /*Declare the external environment variable array*/
void execmd(char **argv);
char *get_location(char *command);
void execute(int num_tokn, char **argv, char *copy_cmd, char *full_cmd);
int token_count(char *copy_command, char *full_command);
char *directory_path(int command_length, char *path_token, char *command);
char *_strdup(char *str);
char *_strcat(char *destination, char *source);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _putchar(char c);
int put_s(char *str);
bool builtin_check(const char *command);
void builtin_handler(char **argv, char *copy_cmd, char *full_cmd, int num_tokn);
void _env(void);
void exit_func(char **argv, char *copy_cmd, char *full_cmd, int num_tokn);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delim);
#endif
