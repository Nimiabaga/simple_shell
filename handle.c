#include "shell.h"
/**
 * process_cmdline - Process the command line by executing the command.
 * @cmd_line: The entire command line including the command and its arguments.
 */
void process_cmdline(char **cmd_line)
{
	char *cmd_name = cmd_line[0];
	char *cmd_path;

    /* Check if the command is a built-in command */
	if (my_builtins(cmd_line))
	{
		return;
	}
	/* Check if the command contains a path (e.g., /usr/bin/ls) */
	if (strchr(cmd_name, '/'))
	{
		run_command(cmd_name, cmd_line);
	}
	else
	{
	/* Find the full path of the command */
		cmd_path = find_full_path(cmd_name);
		if (cmd_path == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", cmd_name);
			exit(EXIT_FAILURE);
		}
	/* Execute the command with arguments */
		run_command(cmd_path, cmd_line);
	}
}




/**
 * run_command - Execute a command with the given arguments.
 * @command: The command to be executed.
 * @arguments: The arguments for the command.
 *
 * Returns: The exit status of the executed command.
 */
void run_command(char *command, char **arguments)
{
	pid_t child_pid;
	int child_status;
	char *envp[] = {"TERM=xterm", NULL};

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Failed to execute the command");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(command, arguments, envp) == -1)
		{
			perror("Execution of the command failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &child_status, 0);
	}
}




