#include "main.h"
/**
 * main - entry point
 *
 * Return: 0 always succes.
*/
int main(void)
{
	size_t bufsize = 0, length, index = 0;
	ssize_t bytesread;
	char *buffer = NULL, *buffer_copy;
	int re_turn_value = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		bytesread = getline(&buffer, &bufsize, stdin);
		if (bytesread == -1)
		{
			printf("\n");
			break;
		}
		buffer[bytesread - 1] = '\0';
		length = 0;
		buffer_copy = buff_copy(buffer_copy, length, buffer, index);
		if (!strcmp(buffer_copy, "exit"))
			exit(EXIT_FAILURE);
		re_turn_value = PATH_analyse(buffer_copy);
		if (re_turn_value == 1)
		{
			if (!strcmp(buffer_copy, "env"))
				print_environment();
			else if (!strcmp(buffer_copy, "cd"))
			{
				if (chdir(buffer + length + 1) != 0)
					perror("cd");
			}
			else
				execute_command(buffer);
		}
		else
			printf("%s: command not found\n", buffer_copy);
		free(buffer_copy);
	}
	free(buffer);
	return (0);
}
