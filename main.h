#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of string pointers */
extern char **environ;


/**
 * struct info - struct stores all relevant info on runtime
 * @argv: argument vector
 * @input: command line by the user
 * @args: tokens of the cmd line
 * @status: last status of the sh
 * @count: lines count
 * @_envrn: environ variable
 * @p_id: process_ID of the sh
 */
typedef struct info
{
	char **argv;
	char *input;
	char **args;
	int status;
	int count;
	char **_envrn;
	char *p_id;
} datashell;

/**
 * struct separator_l - a singly_linked list
 * @sep: ; | &
 * @next: next_node
 * Description: singly_linked list for storing separators
 */
typedef struct separator_l
{
	char sep;
	struct separator_l *next;
} list_sep;

/**
 * struct line_l - singly_linked list
 * @line: cmd line
 * @next: next_node
 * Description: singly_linked list to store cmd lines
 */
typedef struct line_l
{
	char *line;
	struct line_l *next;
} list_line;

/**
 * struct r_var_li - singly_linked list
 * @len_var: len of var
 * @val: value of var
 * @len_val: len of value
 * @next: next_node
 * Description: singly_linked list for storing var
 */
typedef struct r_var_li
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_li *next;
} var_li;

/**
 * struct _builtin_ - Builtin struct for cmd args.
 * @name: The name of cmd builtin.
 * @f: function pointer.
 */
typedef struct _builtin_
{
	char *name;
	int (*f)(datashell *data_sh);
} _builtin;

/* lists_aux.c */
list_sep *add_sep_end(list_sep **head, char sep);
void free_list_sep(list_sep **head);
list_line *add_line_end(list_line **head, char *line);
void free_list_line(list_line **head);

/* lists2_aux.c */
var_li *_add_rvar_node_end(var_li **head, int lvar, char *var, int lval);
void free_var_li(var_li **head);

/* str_aux functions */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/* mem_aux.c */
void _memcpy(void *newpointr, const void *pointr, unsigned int size);
void *_realloc(void *pointr, unsigned int old_len, unsigned int new_len);
char **_realloc_dp(char **pointr, unsigned int old_len, unsigned int new_len);

/* str2_aux.c */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_char_len(char arr[], const char *delim);
char *_strtok(char arr[], const char *delim);
int _isdigit(const char *s);

/* str3_aux.c */
void rev_string(char *s);

/* error_check_syntax.c */
int num_repeated_char(char *input, int index);
int error_snytx(char *input, int index, char last);
int indx_first_char(char *input, int *index);
void print_syntx_err(datashell *data_sh, char *input, int i, int bool);
int check_syntx_error(datashell *data_sh, char *input);

/* loop_shell.c */
char *_without_comment(char *input);
void _shell_loop(datashell *data_sh);

/* line_read.c */
char *_read_line(int *line_val);

/* _split.c */
char *_swap_char(char *input, int bool);
void _add_nodes(list_sep **head_s, list_line **head_l, char *input);
void _go_next(list_sep **list_s, list_line **list_l, datashell *data_sh);
int _split_commands(datashell *data_sh, char *input);
char **_split_line(char *input);

/* var_rep.c */
void _check_env(var_li **h, char *in, datashell *data);
int _check_vars(var_li **h, char *in, char *st, datashell *data);
char *_replaced_input(var_li **head, char *input, char *new_input, int nlen);
char *_replace_var(char *input, datashell *data_sh);

/* line_get.c */
void _bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t _get_line(char **lineptr, size_t *n, FILE *stream);

/* line_exec */
int _exec_line(datashell *data_sh);

/* exec_cmd.c */
int _is_cdir(char *path, int *i);
char *_which_(char *cmd, char **_environ);
int _is_executable(datashell *data_sh);
int check_err_cmd(char *dir, datashell *data_sh);
int _cmd_exec(datashell *data_sh);

/* env_1.c */
char *_getenv(const char *name, char **_environ);
int _env(datashell *data_sh);

/* env_2.c */
char *copy_info(char *name, char *value);
void _set_env(char *name, char *value, datashell *data_sh);
int _setenv(datashell *data_sh);
int _unsetenv(datashell *data_sh);

/* _cd.c */
void cd_paren(datashell *data_sh);
void cd_given(datashell *data_sh);
void cd_prev_dir(datashell *data_sh);
void cd_to_home_dir(datashell *data_sh);

/* shell_cd.c */
int _cd_shell(datashell *data_sh);

/* builtin_get */
int (*_get_builtin(char *cmd))(datashell *data_sh);

/* exit_shell.c */
int _exit_shell(datashell *data_sh);

/* stdlib_aux.c */
int get_length(int n);
char *_itoa_(int n);
int _atoi_(char *s);

/* err1_aux.c */
char *strcat_cd_er(datashell *, char *, char *, char *);
char *error_msg_get_cd(datashell *data_sh);
char *error_cmd_not_found(datashell *data_sh);
char *err_exit_shell(datashell *data_sh);

/* err2_aux.c */
char *error_get_alias(char **args);
char *error_msg_env(datashell *data_sh);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_msg_path(datashell *data_sh);


/* err_get.c */
int _get_err(datashell *data_sh, int err_val);

/* sig_handle.c */
void _get_sigint(int signal);

/* help_aux.c */
void aux_help_env_info(void);
void aux_help_setenv_info(void);
void aux_help_unsetenv_info(void);
void aux_help_general_info(void);
void aux_help_exit_info(void);

/* help2_aux.c */
void aux_help_info(void);
void aux_help_alias_info(void);
void aux_help_cd_info(void);

/* help_get.c */
int _get_help(datashell *data_sh);

#endif
