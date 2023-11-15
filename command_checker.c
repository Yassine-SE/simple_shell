#include "shell.h"

/**
 * command_checker - check
 * @cm: param
 *
 * Return: Always 0.
 */
void command_checker(char *cm)
{
	if (access(cm, F_OK) == 0)
	{
		printf("%s: Found\n", cm);
	}
	else
	{
		printf("%s: Not Found\n", cm);
	}
}
