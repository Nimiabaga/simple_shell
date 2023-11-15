#include "shell.h"

/**
 * my_builtins - Handles built-in commands
 * @cmd: Parsed command and its arguments.
 *
 * This function checks for built-in commands and executes them if found.
 *
 * Return: 1 if a built-in command was handled, 0 otherwise.
 */
int my_builtins(char **cmd)
{
	if (cmd == NULL || cmd[0] == NULL)
	{
		return (0);
	}
	if (strcmp(cmd[0], "execute_setenv") == 0 && cmd[1] != NULL && cmd[2] != NULL)
	{
		return (execute_setenv(cmd[1], cmd[2]));
	}
	else if (strcmp(cmd[0], "execute_unsetenv") == 0 && cmd[1] != NULL)
	{
		return (execute_unsetenv(cmd[1]));
	}
	else if (strcmp(cmd[0], "execute_env") == 0)
	{
		execute_env(cmd);
		return (1);
	}
	else if (strcmp(cmd[0], "cd") == 0)
	{
	/* Handle the cd command */
		my_cd(cmd + 1);
		return (1);
	}
	else if (strcmp(cmd[0], "exit") == 0)
	{
	/* Handle the exit command with an argument */
		if (cmd[1] != NULL)
		{
			int status = atoi(cmd[1]);

			exit(status);
		}
		else
		{
	/* Default exit without status argument */
			exit(0);
		}
	}
    /* No built-in command found */
	return (0);
}

