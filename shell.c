#include "shell.h"
int main(int argc, char **argv);


/**
 * main - Entry point for a simple shell program.
 * @argc: Argument count
 * @argv: Argument values
 * Return: Always returns 0
 */
int main(int argc, char **argv)
{
	ssize_t input_length;
	char *data_input = NULL;
	size_t buffer_size = 0;
	(void)argc;
	(void)argv;
	while (1)
	{
		input_length = user_input(&data_input, &buffer_size);
		if (input_length == -1)
		{
			break; /* Break the loop if an error occurred during input. */
		}
		if (data_input[0] == '#' || (data_input[0] == ' ' && data_input[1] == '#'))
		{
			continue; /* Skip lines starting with '#' or '##'. */
		}

	/* Check for the "exit" command */
		if (startsWith(data_input, "exit"))
		{
			int status;

			pid_t child_pid = fork();

			if (child_pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			if (child_pid == 0)
			{
				tokenize_input(data_input);
				_exit(EXIT_SUCCESS);
			}
			else
			{
				waitpid(child_pid, &status, 0);
				if (WIFEXITED(status))
				{
					exit_shell(WEXITSTATUS(status));
				}
				else
				{
					exit_shell(EXIT_FAILURE);
				}
			}
		}
		tokenize_input(data_input); /* Update to data_input */
	}
	free(data_input);
	return (EXIT_SUCCESS);
}

