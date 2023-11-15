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
	char *line = NULL, *cmd_path;
	size_t line_len = 0;
	ssize_t noc = 0;
	char **token_array = NULL;
	(void) ac;
	(void) av;
	(void) env;

	while (1)
	{
		write(1, "$ ", 2);
		noc = getline(&line, &line_len, stdin);
		if (noc == -1)
			exit(EXIT_FAILURE);

		token_array = tokens_list(line);
		if (strcmp(token_array[0], "exit") == 0)
			exit(EXIT_SUCCESS);

		cmd_path = command_checker(token_array[0]);
		printf("path: %s\n", cmd_path);

		/*if (cmd_path)
			process_handler(cmd_path, token_array, env);
		else
			printf("hsh: %lu: %s: not found\n", strlen(token_array[0]), token_array[0]);*/

		free(cmd_path);
		free(token_array);
		free(line);
	}
	exit(EXIT_SUCCESS);
}
