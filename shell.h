#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

char **tokens_list(void);
char *command_checker(char *cm);
void process_handler(char **token_array, char **env);
char *_getenv(const char *name);

#endif
