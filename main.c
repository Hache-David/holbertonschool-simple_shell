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

	while (1)
	{
		if (isatty(STDIN_FILENO)) /* Vérifie si le shell tourne en mode "interactif" */
		{

			printf("hsh $ ");
		}

		bytesread = getline(&buffer, &bufsize, stdin);
		
			pid_number = fork();


			execl(return_PATH(), "ls", (char *)NULL);
		
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
	return (0);
}
