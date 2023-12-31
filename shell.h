#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/* #include <sys/wait.h>*/
#include <sys/stat.h>

extern char **environ;

char *user_input(void);
char **tokens_list(char *line);
char *command_checker(char *cmd);
void error_handler(char *file, char *msg);

void process_handler(char *cmd_path, char **token_array, char **env);
char *_getenv(const char *name);

#endif
