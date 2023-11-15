#include "shell.h"

/**
 * command_checker - check
 * @cmd: param
 *
 * Return: Always 0.
 */
char *command_checker(char *cmd)
{
	char *path = _getenv("PATH");
	char *token = NULL;
	char *cmd_path = NULL;
	struct stat st;

	printf("checker = %s\n", path);
	token = strtok(path, ":");
	while (token)
	{
		cmd_path = malloc(strlen(token) + strlen(cmd) + 2);
		strcpy(cmd_path, token);
		strcat(cmd_path, "/");
		strcat(cmd_path, cmd);

		printf("while = %s\n", cmd_path);
		if (stat(cmd_path, &st) == 0)
		{
			free(path);
			return (cmd_path);
		}

		free(cmd_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
