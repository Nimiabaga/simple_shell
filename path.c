#include "shell.h"

/**
 * find_full_path - Find the full path of a command.
 * @command: The name of the command.
 *
 * Return: On success, returns the full path of the command.
 * On failure or if the command is not found, returns NULL.
 */
char *find_full_path(const char *command)
{
	const char *path_env = getenv("PATH");
	char *clone_path;
	char *folder;

	if (path_env == NULL)
	{
	fprintf(stderr, "PATH environment variable is not set\n");
}
	folder = strtok(NULL, ":");
	}
	free(clone_path);
	return (NULL);
}
