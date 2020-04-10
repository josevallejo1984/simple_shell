#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define PATH_DELIMIT "=:"
#define DELIMIT " \t\r\n\a"
#define BUFF_MAX 10 /* max buffer size*/
#define MAXLIST 100 /* max number of commands to be supported.*/
#define STDOUT STDOUT_FILENO /* abbreviating this variable.*/
#define CLEAR_SCREEN write(STDOUT, "\033[H\033[J", 6) /*a macro*/
#define NEW_LINE write(STDOUT, "\n", 1) /*a macro*/

/* prototypes owner */
char *_getlines(void);
int _strcmp(char *s1, char *s2);
char **_strtok(char *argv);
int _execev(char **argvs);
char *_strcat(char *dest, char *src);
void initiate_shell(void);
void prompt_shell(void);
char **free_dp(char **dp);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
int _strlen(char *s);
char **get_path(char **env);
#endif
