#include "shell.h"

void tokenize_input(char *data_input);


/**
 * startsWith - Check if a string starts with a given prefix.
 * @str: The string to check.
 * @prefix: The prefix to check for at the beginning of the string.
 * Return: 1 if the string starts with the prefix, 0 otherwise.
 */
int startsWith(const char *str, const char *prefix)
{
	size_t prefixLength = strlen(prefix);
	size_t strLength = strlen(str);

	if (prefixLength > strLength)
	return (0);
	return (strncmp(str, prefix, prefixLength) == 0);
}

/**
 * tokenize_input - Tokenize the input string into an array of strings
 * @data_input: Input string to be tokenized
 *
 * Description: This function takes an input string and tokenizes it
 * using a specific delimiter. The resulting tokens are stored in an array
 * of strings, and the array is terminated with a NULL pointer.
 */


void tokenize_input(char *data_input)
{
	char *token;
	char *strtrim = data_input;
	char *end = strtrim + strlen(strtrim) - 1;
	char *input_copy = " \t\n";
	char *tokens[1024];
	int token_count = 0;
	int i;
	int j;

	for (i = 0; i < 1024; i++)
	{
		tokens[i] = NULL;
	}
	while (*strtrim == ' ' || *strtrim == '\t')
	{
		strtrim++;
	}
	while (end > strtrim && (*end == ' ' || *end == '\t'))
	{
		*end = '\0';
		end--;
	}
	token = strtok(strtrim, input_copy);
	for (i = 0; token != NULL; i++)
	{
		tokens[i] = strdup(token);
		if (tokens[i] == NULL)
		{
			perror("Tokenization error");
			exit(EXIT_FAILURE);
		}
		token_count++;
		token = strtok(NULL, input_copy);
	}
	if (token_count > 0)
	{
		if (!my_builtins(tokens))
		{
			process_cmdline(tokens);
		}
	}
	for (j = 0; j < token_count; j++)
	{
		free(tokens[j]);
	}
}
