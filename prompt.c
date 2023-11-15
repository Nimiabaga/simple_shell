#include "shell.h"

/**
 * user_input - Read and parse user input.
 * @input: Pointer to the input line buffer.
 * @data: Size of the input buffer.
 *
 * Return: Number of characters read or -1 on error.
 */
int user_input(char **input, size_t *data)
{
	char *call = "n$ ";  /* The prompt to be displayed */
	int command;
	int direct_input = isatty(STDIN_FILENO);

	if (direct_input)
	{
		write(STDOUT_FILENO, call, strlen(call));
	}
	command = getline(input, data, stdin);  /* Read input line */
	if (command == -1)  /* Handle Ctrl+D (EOF) */
	{
		if (direct_input)
			write(STDOUT_FILENO, "\n", 1);
		return (-1);
	}
	if (direct_input && command > 0 && (*input)[command - 1] == '\n')
	{
		(*input)[command - 1] = '\0';
		command--;
	}
	return (command);  /* Return the number of characters read */
}

