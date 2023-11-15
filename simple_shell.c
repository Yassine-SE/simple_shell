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
	char *line = NULL, **token_array = NULL;
	char *cmd_path = NULL;
	int j;
	(void) ac;
	// (void) av;
	(void) env;

	while (1)
	{
		line = user_input();
		if (!line)
			exit(EXIT_FAILURE);

		token_array = tokens_list(line);
		if (strcmp(token_array[0], "exit") == 0)
		{
			write(1, "= ", 2);
			exit(EXIT_SUCCESS);
		}

		cmd_path = command_checker(token_array[0]);
		if (cmd_path)
		{
			printf("Found\n");
		}
		else
		{
			printf("%s: No such file or directory\n", av[0]);
		}


		/*if (cmd_path)
			process_handler(cmd_path, token_array, env);
		else
			printf("hsh: %lu: %s: not found\n", strlen(token_array[0]), token_array[0]);*/

		free(cmd_path);
		for (j = 0; token_array[j]; j++)
			free(token_array[j]);
		free(token_array);
	}

	exit(EXIT_SUCCESS);
}
