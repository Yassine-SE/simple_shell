#include "shell.h"

/**
 * error_handler - Error
 *
 * Return: Always 0.
 */
void error_handler(char *file, char *msg)
{
	write(1, file, strlen(file));
	write(1, msg, strlen(msg));
	write(1, "\n", 1);
}
