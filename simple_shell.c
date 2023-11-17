#include "shell.h"

/**
 * main - Simple shell
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char *line;
	char **token_array = NULL;
	(void) ac;

	while (1)
	{
		line = user_input();
		if (!line)
			exit(EXIT_FAILURE);

		if (strlen(line) > 1)
		{
			token_array = tokens_list(line);

			if (execve(token_array[0], token_array, NULL) == -1)
				error_handler(av[0], " : No such file or directory");
			else
				error_handler(av[0], " : Command found");
		}

		free(token_array);
	}
	exit(EXIT_SUCCESS);
}
