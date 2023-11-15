#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * my_exit handles the "exit" built-in command.
 *
 * @args: Array of arguments, including the command itself
 * @status: Pointer to the shell's exit status
 */
void my_exit(char **args, int *status)
{
	if (args[1] != NULL)
	{
	/* Convert the provided argument to an unsigned integer */
	unsigned int exit_status = atoi(args[1]);

	if (exit_status == 0 && args[1][0] != '0')
	{
	write(STDERR_FILENO, "Error: Invalid argument for exit\n", 34);
	return;
	}

	*status = exit_status;
	}

	/* Exit the shell */


	exit(*status);
}

void exit_shell(int status)
{
	_exit(status);
}
