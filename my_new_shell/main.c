#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void)
{
    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t prompt;
    
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

        // fork my parent process //

        
    }
    return (0);
}