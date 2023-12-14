#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
extern char **environ;

int main(void)
{
    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t prompt;
	pid_t pid;
	char *argv[] = {"/bin/ls", "-l", NULL}; // tokéniser ça //
	int check_exec;

    while(1)
    {
        printf("##FirstShell $ ");
        prompt = getline(&buffer, &buffer_size, stdin);

        if (prompt == -1)
        {
            printf("\n");
            break;
        }

        // check if command is true //
		//--> tokenisation ://

		// fork my parent process //
		pid = fork();

		if (pid == -1)
		{
			return (-1);
		}
		if (pid == 0) /* in child process */
		{
			check_exec = execve(argv[0] , argv, NULL);
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
