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
			execve(command, token_array, env);
		}
		else
		{
			printf("Command not found\n");
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&status);
	}
}
