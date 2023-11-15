#include "shell.h"

/**
 * tokens_list - tokens
 *
 * Return: Always 0.
 */
char **tokens_list(void)
{
	char *line;
	size_t line_len;
	char *token;
	char **token_array = NULL;
	int noc = 0, i = 0;
	
	noc = getline(&line, &line_len, stdin);
	if (noc == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}

	token_array = malloc(sizeof(char *) * 1024);
	if (!token_array)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

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
