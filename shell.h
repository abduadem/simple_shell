#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> /*used for printf(added for task-1)*/
#include <stdlib.h> /*(added for task-1)*/
#include <unistd.h> /*used for ssize_t (added for task-1)*/
#include <sys/types.h> /*used for wait() (added for task-1)*/
#include <sys/wait.h> /*used for wait() (added for task-1)*/
#include <string.h> /*used for string(added for task-2)*/

void prompt(char **av, char **env); /*for function prompt.c*/

#endif

