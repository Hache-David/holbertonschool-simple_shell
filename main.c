#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <stddef.h>
extern char **environ;
int main(void)
{
	pid_t pid_number;
	size_t bufsize = 0;
	ssize_t bytesread;
	char *args[] = {"ls", NULL};
	/*char *envp[] = {NULL};*/
	size_t length = 0;
	char *buffer = NULL;
	char *buffer_copy;
	size_t index;
	int return_value = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO)) /* Vérifie si le shell tourne en mode "interactif" */
		{
			printf("hsh $ ");
		}

		bytesread = getline(&buffer, &bufsize, stdin); /* copie input in buffer */

		if (bytesread == -1)
			return (0);
		while (buffer[length] != ' ' && buffer[length] != '\0') /* length of first command */
			length++;
	
    	buffer_copy = malloc(sizeof(char) * (length + 1));

		if (buffer_copy == NULL)
			return (0);
	
    	for (index = 0; index < length; index++) /* copy command on buffer_copy */
			buffer_copy[index] = buffer[index];

		return_value = PATH_analyse(buffer_copy);

		if(return_value == 0)
		{

			pid_number = fork();

			if (bytesread == -1) 
			{
				printf("\n");
				break;
			}

			if (!strcmp(buffer, "exit\n"))
				break;

			if (!strcmp(buffer, "env\n"))
			{
				char **env = environ;
				while (*env != NULL)
				{
					printf("%s\n", *env);
					env++;
				}
			}

			if (pid_number < 0)
			{
				printf("Error Fork\n");
				exit(EXIT_FAILURE);
			}
			if (pid_number == 0)
			{
				printf ("%s", return_PATH(buffer_copy));
				execve(return_PATH(buffer_copy), args, environ);
				/*execve("/bin/ls", args , envp);*/
				perror("execve");
        		exit(EXIT_FAILURE);
			}
			else
			{
				waitpid(pid_number, NULL, 0);
			}
		}
	}
	return (0);
}
