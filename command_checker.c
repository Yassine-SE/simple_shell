#include "shell.h"

/**
 * command_checker - check
 * @cm: param
 *
 * Return: Always 0.
 */
char *command_checker(char *cm)
{
	char *path = _getenv("PATH");
	char *token, *command;
	struct stat st;

	token = strtok(path, ":");
	while (token)
	{
		command = malloc(strlen(token) + strlen(cm) + 2);
		strcpy(command, token);
		strcat(command, "/");
		strcat(command, cm);

		if (stat(command, &st) == 0)
		{
			return (command);
		}

		free(command);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
