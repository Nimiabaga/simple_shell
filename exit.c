#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * my_exit - Handle the "exit" built-in command.
 * @args: Array of arguments, including the command itself.
 * @status: Pointer to the shell's exit status.
 *
 * This function handles the "exit" command in the shell. If an argument is
 * provided, it interprets it as the exit status; otherwise, it uses the
 * default exit status.
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

/**
 * exit_shell - Exit the shell with a given status code.
 * @status: The exit status code.
 *
 * This function is responsible for terminating the shell with the specified
 * status code.
 */
void exit_shell(int status)
{
	_exit(status);
}
