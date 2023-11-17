#include "shell.h"

/**
 * command_checker - check
 * @cmd: param
 *
 * Return: Always 0.
 */
char *command_checker(char *cmd)
{
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
}
