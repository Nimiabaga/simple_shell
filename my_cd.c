#include "shell.h"
void my_cd(char **args);

/**
 * my_cd - Change the current working directory in the shell
 * @args: Array of arguments, including the command itself
 *
 * This function implements the 'cd' command, allowing the user
 * to change the current working directory.
 */
void my_cd(char **args)
{
	char *target_directory, *full_target_directory;
	char *current_directory;

    /* If no arguments, change to the home directory */
	if (args == NULL || args[0] == NULL)
	{
		target_directory = getenv("HOME");
		if (target_directory == NULL)
			return;
	}
    /* If the argument is "-", change to the previous directory */
	else if (strcmp(args[0], "-") == 0)
		target_directory = getenv("OLDPWD");
    /* Otherwise, change to the specified directory */
	else
		target_directory = args[0];

    /* If the target directory is not set, print the current directory */
	if (target_directory == NULL)
	{
		fprintf(stdout, "%s\n", getenv("PWD"));
		return;
	}

    /* Get the current directory */
	current_directory = getcwd(NULL, 0);
	if (current_directory == NULL)
		return;

    /* Attempt to change to the new directory */
	if (chdir(target_directory) != 0)
		fprintf(stderr, "cd: %s: No such file or directory\n", args[0]);
	else
	{
	/* On successful directory change, update environment variables */
		full_target_directory = getcwd(NULL, 0);
		if (setenv("PWD", full_target_directory, 1) != 0)
			perror("cd");
		if (setenv("OLDPWD", current_directory, 1) != 0)
			perror("cd");

	/* If the argument is "-", print the current directory */
		if (args[0] && strcmp(args[0], "-") == 0)
			fprintf(stdout, "%s\n", getenv("PWD"));
	}

    /* Free allocated memory */
	free(current_directory);
	free(full_target_directory);
}

