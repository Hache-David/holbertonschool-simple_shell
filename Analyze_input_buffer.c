#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *return_PATH(const char *buffer_copy)
{
	char *PATH = "/usr/bin/";
	char *newstring;

	newstring = malloc(strlen(PATH) + strlen(buffer_copy) + 1);
	if (newstring == NULL)
		return (0);
	if (buffer_copy == NULL)
		return (0);
	strcpy(newstring, PATH);
	strcat(newstring, buffer_copy);

	return (newstring);
}
