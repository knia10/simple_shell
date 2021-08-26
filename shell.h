#ifndef SHELL_H
#define SHELL_H

/* Libraries */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/* Structs */
/**
 * struct list - linked list of environmental variables
 * @var: holds environmental variable string
 * @next: points to next node
 */

typedef struct list
{
	char *var;
	struct list *next;

} list_t;

/* Prototypes */
int f_prompt(char **env);
void ctrl_C(int n);
size_t _getline(char **str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int t_strlen(char *str, int pos, char delm);
char *forget_space(char *str);
char **_string_tok(char *str, char *delm);
char **c_string_tok(char *str, char *delm);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int built_in(char **token, list_t *env, int num, char **lineptr);
void non_interactive_mode(list_t *env);
char *_which(char *str, list_t *env);
int f_exit(char **s, list_t *env, int num, char **lineptr);
int _execute(char *argv[], list_t *env, int num);
void free_pptr(char **str);
void free_linked_list(list_t *list);
int print_env(char **str, list_t *env);
char *get_env(char *str, list_t *env);
list_t *linked_list_env_var(char **env);
list_t *new_node(list_t **head, char *str);
size_t print_list(list_t *h);
int find_env(list_t *env, char *str);
void not_found(char *str, int num, list_t *env);
void illegal_number(char *str, int c_n, list_t *env);
char *int_to_str(int num);

#endif
