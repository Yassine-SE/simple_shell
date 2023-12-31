#include "shell.h"

/**
 * user_input - Input
 *
 * Return: Always 0.
 */
char *user_input(void)
{
	char *line = NULL;
	size_t line_len = 0;
	ssize_t noc = 0;

	write(1, "$ ", 2);
	noc = getline(&line, &line_len, stdin);
	if (noc == -1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);

		write(1, "\n", 1);
		free(line);
		return (NULL);
	}

	return (line);
}
