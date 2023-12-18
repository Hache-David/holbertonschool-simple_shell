#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

int main(void)
{
    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t prompt;
	pid_t pid;
	char **argv; // tokéniser ça //
	int check_exec;
	char *token;
	int index_token = 0;
	size_t len_token;

    while(1)
    {
        printf("##FirstShell $ ");
        prompt = getline(&buffer, &buffer_size, stdin);

        if (prompt == -1)
        {
            printf("\n");
            break;
        }
		//--> tokenisation ://
		token = strtok(buffer, " ");

		while (token) // copie chaque token dans argv pour exceve //
		{
			argv[index_token] = malloc(sizeof(char) * strlen(token));
			argv[index_token] = token;
			index_token++;
			token = strtok(NULL, " "); // passer aux token suivant //
		}
		// check if command is true //

		// fork my parent process //
		pid = fork();

		if (pid == -1)
		{
			return (-1);
		}
		if (pid == 0) /* in child process */
		{
			check_exec = execve("/bin/ls" , argv, NULL); // /bin/ls remplacée par PATH //
			if (check_exec == -1)
				perror("./shell: No such file or directory");
		}
		else /* in parent process */
		{
			wait(NULL);
		}


    }
    return (0);
}
