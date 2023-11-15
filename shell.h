#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char **tokens_list(void);
void command_checker(char *cm);
void process_handler(char *token_array);
char *_getenv(const char *name);

#endif
