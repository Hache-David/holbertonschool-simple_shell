#include "main.h"
/**
 * main - entry point
 *
 * Return: 0 always succes.
*/
int main(void)
{
	size_t bufsize = 0;
	ssize_t bytesread;
	char *buffer = NULL;
	char *buffer_copy;
	size_t index;
	int return_value = 0;
	size_t length;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("hsh $ ");
			fflush(stdout);
		}

		bytesread = getline(&buffer, &bufsize, stdin);
		if (bytesread == -1)
		{
			printf("\n");
			break;
		}

		buffer[bytesread - 1] = '\0';

		length = 0;

		while (buffer[length] != ' ' && buffer[length] != '\0')
			length++;

		buffer_copy = malloc(sizeof(char) * (length + 1));
		if (buffer_copy == NULL)
		{
			perror("malloc");
			return (EXIT_FAILURE);
		}

		for (index = 0; index < length; index++)
			buffer_copy[index] = buffer[index];

		buffer_copy[length] = '\0';

		return_value = PATH_analyse(buffer_copy);
		if (return_value == 1)
		{
			if (!strcmp(buffer_copy, "exit"))
				break;
			else if (!strcmp(buffer_copy, "env"))
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
