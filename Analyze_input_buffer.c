#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *return_PATH(char *toks)
{
    char *PATH = "/bin/";
    char *newstring;

    newstring = malloc(strlen(PATH) + strlen(toks) + 1);
    if ( newstring == NULL)
        return (0);
    if (toks == NULL)
        return (0);
    strcpy(newstring, PATH); 
    strcat(newstring, toks);

    return (newstring);
    /*return (execl("bin/%s", "%s", (char *)NULL));*/
}