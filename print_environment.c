#include "main.h"
/**
 * print_environment - Function that rint the current environment variables
*/
void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
