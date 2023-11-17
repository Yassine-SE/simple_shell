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

	if (stat(cmd, &st) == 0)
		return (cmd);

	return (NULL);
}
