#include "shell.h"

/**
 * command_checker - check
 * @cmd: param
 *
 * Return: Always 0.
 */
char *command_checker(char *cmd)
{
	char *dir_tok, *cmd_path, *path;
	struct stat st;
	int j;

	for (j = 0; cmd[j]; j++)
	{
		if (cmd[j] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (strdup(cmd));
			return (NULL);
		}
	}

	path = _getenv("PATH");
	if (!path)
		return (NULL);

	dir_tok = strtok(path, ":");
	while (dir_tok)
	{
		cmd_path = malloc(strlen(dir_tok) + strlen(cmd) + 2);
		if (!cmd_path)
			exit(EXIT_FAILURE);

		strcpy(cmd_path, dir_tok);
		strcat(cmd_path, "/");
		strcat(cmd_path, cmd);
		if (stat(cmd_path, &st) == 0)
		{
			free(path);
			return (cmd_path);
		}
		free(cmd_path);
		cmd_path = NULL;
		dir_tok = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
