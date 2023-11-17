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
	char **token_array;
	int count = 0;
	int i = 0;

	line_cp = strdup(line);
	token = strtok(line_cp, " \t\n");
	while (token)
	{
		count++;
		token = strtok(NULL, " \t\n");
	}
	free(line_cp);

	token_array = malloc(sizeof(char *) * (count + 1));
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
