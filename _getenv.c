#include "shell.h"

/**
 * _getenv - get
 * @name: param
 *
 * Return: Always 0.
 */
char *_getenv(const char *name)
{
	extern char **environ;
	char *env_key;
	int i = 0;

	while (environ[i])
	{
		env_key = strtok(environ[i], "=");
		if (strcmp(env_key, name) == 0)
		{
			return (strtok(NULL, "\n"));
		}
		i++;
	}
	return (NULL);
}
