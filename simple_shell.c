#include "shell.h"

/**
 * main - Simple shell
 *
 * Return: Always 0.
 */
int main(void)
{
	char **token_array;

	while (1)
	{
		write(1, "$ ", 2);

		token_array = malloc(sizeof(char *) * 1024);
		if (!token_array)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		token_array = tokens_list();
		process_handler(token_array);

		free(token_array);
	}
	exit(EXIT_SUCCESS);
}
