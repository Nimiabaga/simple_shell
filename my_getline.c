
#include "shell.h"
#define READ_SIZE 256

char *my_getline();


/**
 * my_getline - Custom function to read a line from standard input
 *
 * Return: On success, returns a pointer to the line read.
 *         On failure or EOF, returns NULL.
 */
char *my_getline()
{
	static char buffer[READ_SIZE];
	static char *buf_pos = buffer;
	static int bytes_read;
	char *line = NULL;
	size_t line_size = 0;
	size_t new_size;

	while (1)
	{
		char c = *buf_pos;

		if (c == '\0')
		{
			if (bytes_read <= 0)
			{
				if (line != NULL)
					free(line);
				return (NULL);
			}
			bytes_read = read(STDIN_FILENO, buffer, READ_SIZE);
			if (bytes_read <= 0)
			{
				if (line != NULL)
					free(line);
				return (NULL);
			}
			buf_pos = buffer;
			continue;
		}
		if (c == '\n')
		{
			*buf_pos = '\0';
			return (line);
			if (line_size % READ_SIZE == 0)
			{
				new_size = line_size + READ_SIZE;
				line = (char *)realloc(line, new_size);
				if (line == NULL)
				{
					perror("Allocation error");
					exit(EXIT_FAILURE);
				}
			}
			line[line_size++] = c;
			++buf_pos;
		}
	}
}

