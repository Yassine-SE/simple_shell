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
	char **token_array = NULL;
	(void) ac;
	(void) av;

	while (1)
	{
		write(1, "$ ", 2);

		token_array = tokens_list();
		if (strcmp(token_array[0], "exit") == 0)
		{
			exit((EXIT_SUCCESS));
		}
		
		process_handler(token_array, env);

		free(token_array);
	}
	exit(EXIT_SUCCESS);
}
