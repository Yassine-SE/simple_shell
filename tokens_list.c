#include "shell.h"

/**
 * tokens_list - tokens
 * @line: param
 *
 * Return: Always 0.
 */
char **tokens_list(char *line)
{
	char *token, *line_cp;
	char **token_array = NULL;
	int count = 0;
	int i = 0;

	line_cp = strdup(line);
	token = strtok(line_cp, " \t\n");
	while (token)
	{
		count++;
		token = strtok(NULL, " \t\n");
	}

	token_array = malloc(sizeof(char *) * (count + 1));
	if (!token_array)
		exit(EXIT_FAILURE);

	free(line_cp);
	token = strtok(line, " \t\n");
	while (token)
	{
		token_array[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	token_array[i] = NULL;

	free(line);
	return (token_array);
}
