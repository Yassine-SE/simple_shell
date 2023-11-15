#include "shell.h"

/**
 * process_handler - Process
 * @token_array: param
 * @env: param
 *
 * Return: Always 0.
 */
void process_handler(char **token_array, char **env)
{
	int status;
	char *command;
	pid_t pid;
	(void) env;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		command = command_checker(token_array[0]);
		if (command)
		{
			/* execve(token_array[0], token_array, env); */
			printf("exerve is working\n");
		}
		else
		{
			printf("Command not found\n");
		}
	}
	else
	{
		wait(&status);
	}
}
