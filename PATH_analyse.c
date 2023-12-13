#include <sys/stat.h>  
#include <sys/types.h>   
#include <dirent.h>  
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
    
int PATH_analyse(char *buffer_copy)
{
    DIR *directory;
    struct dirent *entry;
	
    directory = opendir("/bin/");
    while ((entry = readdir(directory)) != NULL) 
	{
    	if (strcmp(entry->d_name , buffer_copy) == 0) 
        {
            printf("L'entrée de l'utilisateur correspond à un fichier dans /bin/ : %s\n", entry->d_name);
            return (1);
		}
	}
    return (0);
}
