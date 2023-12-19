#ifndef __MINISHELL__
#define __MINISHELL__

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
extern char **environ;

int PATH_analyse(char *buffer_copy);
void execute_command(char *buffer, char *argv_zero);
void print_environment(void);
char *buff_copy(char *buffer_copy, int length, char *buffer, int index);

#endif
