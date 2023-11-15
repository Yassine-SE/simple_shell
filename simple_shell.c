#include "shell.h"

/**
 * main - Simple shell
 * @ac: param
 * @av: param
 * @env: param
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	char *line;
	size_t line_len;
	int noc = 0;
	char **token_array = NULL;
	(void) ac;
	(void) av;

	while (1)
	{
		write(1, "$ ", 2);

		noc = getline(&line, &line_len, stdin);
		if (noc == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}

		token_array = tokens_list(line);
		if (strcmp(token_array[0], "exit") == 0)
			exit(0);

		process_handler(token_array, env);
		free(token_array);
	}
	exit(EXIT_SUCCESS);
}
