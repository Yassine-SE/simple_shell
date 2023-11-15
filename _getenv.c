#include "shell.h"

/**
 * _getenv - get
 * @name: param
 *
 * Return: Always 0.
 */
char *_getenv(const char *name)
{
	char *env_key, *env_value;
	char *tmp, *env;
	int i = 0;

	while (environ[i])
	{
		tmp = strdup(environ[i]);
		env_key = strtok(tmp, "=");
		if (strcmp(env_key, name) == 0)
		{
			env_value = strtok(NULL, "\n");
			env = strdup(env_value);
			free(tmp);
			return (env);
		}
		free(tmp);
		tmp = NULL;
		i++;
	}
	return (NULL);
}
