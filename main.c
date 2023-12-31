#include "main.h"
/**
 * main - entry point
 *
 *  @argv: value of argument.
 *	@argc: number of input argument.
 * Return: 0 always succes.
*/
int main(int argc, char **argv)
{
	size_t bufsize = 0, length = 0, index = 0;
	ssize_t bytesread;
	char *buffer = NULL;
	char *buffer_copy = NULL;

	if (argc == 0)
		return (2);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		bytesread = getline(&buffer, &bufsize, stdin);
		if (bytesread == -1)
		{
			free(buffer);
			exit(EXIT_SUCCESS); }
		buffer[bytesread - 1] = '\0', length = 0;
		buffer_copy = buff_copy(length, buffer, index);
		if (buffer_copy == NULL)
			free(buffer), exit(EXIT_FAILURE);
		if (!strcmp(buffer_copy, "exit"))
		{
			free(buffer_copy), free(buffer);
			exit(EXIT_SUCCESS); }
		if (PATH_analyse(buffer_copy))
		{
			if (!strcmp(buffer_copy, "env"))
				print_environment();
			else
				execute_command(buffer, argv[0]);
		}
		else if (strlen(buffer_copy) != 0)
			fprintf(stderr, "%s: 1: %s: command not found\n", argv[0], buffer_copy);
		free(buffer_copy);
	}
	free(buffer);
	return (EXIT_SUCCESS); }
