#include "shell.h"

/**
 * process_handler - Process
 * @token_array: param
 *
 * Return: Always 0.
 */
void process_handler(char *token_array)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (execve(token_array[0], token_array, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
