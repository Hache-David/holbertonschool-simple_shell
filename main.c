#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(void)
{
	pid_t pid_number;
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t bytesread;
	char *const argv[] = {"/bin/ls" , NULL};
	char *const envp[] = {NULL};
	char *token;
	int counter = 0;
	char **toks;
	const char delimiters[] = " ";
	int index = 0;
	char *buffer_copy;
	int descripteur;
	int read_file;

	while (1)
	{
		if (isatty(STDIN_FILENO)) /* Vérifie si le shell tourne en mode "interactif" */
		{
			printf("hsh $ ");
		}

		bytesread = getline(&buffer, &bufsize, stdin);

		while (buffer[index] != ' ')
			index++;
	
    		buffer_copy = malloc(sizeof(char) * index);
	
    	for (index = 0; buffer[index] != ' '; index++)
			buffer_copy[index] = buffer[index];
	
		if(PATH_analyse(buffer_copy))
		{
			pid_number = fork();

			execve(return_PATH(buffer_copy), argv, envp);
		
			if (bytesread == -1) 
			{
				printf("\n");
				break;
			}

			if (!strcmp(buffer, "exit\n"))
				break;

		
			if (pid_number < 0)
				printf("Error Fork\n");

			if (pid_number == 0)
			{
				printf("I am the son, my pid is %d\n", pid_number);
			}
			else
			{
				printf("I am the father, my pid is %d\n", pid_number);
			}
		}
	}
	return (0);
}
