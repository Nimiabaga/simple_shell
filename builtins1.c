#include "shell.h"

/
 
execute_setenv - Set an environment variable.
@env_variable: The name of the environment variable.
@data: The value to assign to the environment variable.
Return: 1 on success, 0 on failure.
*/
int execute_setenv(const char env_variable, const chardata)
{
	if (env_variable == NULL || data == NULL)
	{
	fprintf(stderr, "Usage: execute_setenv ENV_VARIABLE DATA\n");
	return (0);
        }
        if (setenv(env_variable, data, 1) == -1)
        {
	perror("execute_setenv");
	return (0);
	}
	return (1);
}

/

execute_unsetenv - Unset an environment variable.
@env_variable: The name of the environment variable to unset.
Return: 1 on success, 0 on failure.
*/
int execute_unsetenv(const char *env_variable)
{
	if (env_variable == NULL)
	{
	fprintf(stderr, "Usage: execute_unsetenv ENV_VARIABLE\n");
	return (0);
	}
}
	if (unsetenv(env_variable) == -1)
	{
	perror("execute_unsetenv");
	return (0);
	}
	return (1);
}



/

execute_env - Execute the env command and list environment variables.
@args: Unused (can be NULL).
*/
void execute_env(char args)
{
	int k = 0;
	char **environment = environ;
	(void)args;

	while (environment[k] != NULL)
	{
	write(STDOUT_FILENO, environment[k], strlen(environment[k]));
	write(STDOUT_FILENO, "\n", 1);
	k++;
	}
}
