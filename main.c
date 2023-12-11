#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t bytesread;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("\xf0\x9f\x91\x8b\xf0\x9f\x98\x8e Best_Shell $ ");
			bytesread = getline(&buffer, &bufsize, stdin);
		}
		if (bytesread == -1)
		{
			printf("\n");
			break;
		}
		if (!strcmp(buffer, "exit\n"))
			break;
	}
	return (0);
}
