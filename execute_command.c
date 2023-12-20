#include "main.h"
/**
 * execute_command - Function that execute the command specified in the buffer
 *
 * @argv_zero: first argument of file main.
 * @buffer: The input buffer containing the command
*/
void execute_command(char *buffer, char *argv_zero)
{
	pid_t pid_number;
	char *args[32];
	int i = 0;
	char command_path[PATH_MAX];
	char *token = strtok(buffer, " ");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	pid_number = fork();
	if (pid_number < 0)
	{
		perror("Error Fork\n");
		exit(EXIT_FAILURE);
	}

	if (pid_number == 0)
	{
		if (strncmp(args[0], "/", 1) == 0)
			sprintf(command_path, "%s", args[0]);
		else
			sprintf(command_path, "/bin/%s", args[0]);
		execve(command_path, args, environ);
		perror(argv_zero);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid_number, NULL, 0);
	}
}
