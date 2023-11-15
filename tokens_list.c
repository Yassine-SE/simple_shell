#include "shell.h"

/**
 * tokens_list - tokens
 * @line: param
 *
 * Return: Always 0.
 */
char **tokens_list(char *line)
{
	char *token = NULL;
	char **token_array = NULL;
	int i = 0;

	token_array = malloc(sizeof(char *) * 1024);
	if (!token_array)
		exit(EXIT_FAILURE);

	token = strtok(line, " \t\n");
	while (token)
	{
		token_array[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	token_array[i] = NULL;

	return (token_array);
}
