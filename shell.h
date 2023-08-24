#ifndef SHELL_H
#define SHELL_H

/* Header Files */
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* Macros */
#define TRUE 1
#define FALSE 0
#define BUFSIZE 1024

/* Global Variables */
extern char **environ;

/**
 * struct t_builtin - Structure for builtin commands
 * @cmmd: the command's name
 * @f: the appropriate function to act on command
 */
typedef struct t_builtin
{
	char *cmmd;
	int (*f)(char **, int, char *);
} t_builtin;

/*----------//My Function Prototypes\\----------*/

/* In executor.c */
int execute(char **cmmd, char *fname);

/* In prompt.c */
void _prompt_init(void);

/* In parser.c */
char *rm_nl(char *line);
char **input_parse(char *line);
char *path_build(char *tokkn, char *value);
int check_cmmd_path(char **cmmd);

/* In getenv.c */
char *_getenv(const char *name);

/* In utils.c */
void memory_free_ptr(char *);
void free_memory_pp(char **);
int cmp(const char *s1, const char *s2);
int _atoi(char *s);
int _isalpha(char c);


/* In printers.c */
int _putchar(int c);
int _prints(char *str);

/* In builtins.c */
int cmmd_exit(char **, int, char *);
int cmmd_env(char **, int, char *);
t_builtin is_builtin(char *cmmd);
int (*check_builtins(char **cmmd))(char **, int, char *);

/* In string.c */
int _strlen(const char *s);
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *destn, const char *src);
char *_strcat(char *destn, const char *src);
int _strcmp(char *a1, char *a2);
char *_strdup(char *s);

#endif

