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
	// int i;
	(void) ac;
	(void) av;
	(void) env;

	while (1)
	{
		line = user_input();
		if (!line)
			exit(EXIT_FAILURE);

		token_array = tokens_list(line);
		if (strcmp(token_array[0], "exit") == 0)
			exit(EXIT_SUCCESS);

		// for (i = 0; token_array[i]; i++)
		// {
		// 	printf("token = %s\n", token_array[i]);
		// }
		

		cmd_path = command_checker(token_array[0]);
		printf("Path = %s\n", cmd_path);

		/*if (cmd_path)
			process_handler(cmd_path, token_array, env);
		else
			printf("hsh: %lu: %s: not found\n", strlen(token_array[0]), token_array[0]);*/

		// free(cmd_path);
		// free(token_array);
		// free(line);
	}

	exit(EXIT_SUCCESS);
}
