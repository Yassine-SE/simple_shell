#include "shell.h"

/**
 * process_handler - Process
 * @token_array: param
 * @env: param
 *
 * Return: Always 0.
 */
void process_handler(char *cmd_path, char **token_array, char **env)
{
	int status;
	char *command;
	pid_t pid;

	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);

	if (pid == 0)
	{
		execve(cmd_path, token_array, env);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&status);
	}
}
