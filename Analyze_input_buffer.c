#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *return_PATH(void)
{
    char *buffer = "ls";
    char *PATH = "/bin/";
    char *newstring;

    newstring = malloc(strlen(PATH) + strlen(buffer) + 1);
    if ( newstring == NULL)
        return (0);
    if (buffer == NULL)
        return (0);
    strcpy(newstring, PATH); 
    strcat(newstring, buffer);

    return (newstring);
    /*return (execl("bin/%s", "%s", (char *)NULL));*/
}