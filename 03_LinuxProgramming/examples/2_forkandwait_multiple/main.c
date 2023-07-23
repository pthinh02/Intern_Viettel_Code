#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>

int main (int argc, char* argv[])
{
    pid_t id1 = fork();
    pid_t id2 = fork();
    while((wait(NULL) != -1) || errno != ECHILD )
    {
        printf("Wait for children\n");
    };

    
    if(id1 == 0)
    {
        if(id2 == 0)    printf("I'm a grand child process\n");
        else if( id2 != 0) printf("I'm x process\n");
    }
    else
    {
        if( id2 == 0) printf("I'm y process\n");
        else printf("I'm parent\n");
    }

    

    
    return 0;
}