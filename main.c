#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t bytesread;

	printf("  |\\    /|\n");
    printf("   \\|___|/\n");
    printf("  / 0   0 \\\n");
	printf("  \\   Y   /\n");
    printf(" ==\\__|__/==\n");
	while (1)
	{
		if (isatty(STDIN_FILENO)) /* Vérifie si le shell tourne en mode "interactif" */
		{

			printf("\xf0\x9f\x91\x8b\xf0\x9f\x98\x8e Best_Shell\xf0\x9f\x96\x95\xf0\x9f\x98\x8e\xf0\x9f\x96\x95 $ ");
			bytesread = getline(&buffer, &bufsize, stdin);
			if (bytesread == -1) 
			{
    	        perror("Error reading input");
    	   	    exit(EXIT_FAILURE);
			}
		}
		else
			printf("./shell: No such file or directory");
	}
	return (0);
}
