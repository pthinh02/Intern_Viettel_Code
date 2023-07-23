#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
//#include <sys/wait.h>


int main (int argc, char* argv[])
{
    pid_t id = fork();
    if(id == 0)
    {
        sleep(1);
    }

    
    printf("Current ID: %d, Parent ID: %d\n",getpid(), getppid());
    
    
    pid_t result = wait(NULL);
    
    if(result > 0)
    {
        printf("Waiting for process ID: %d\n", result);
    }
    else if(result = -1)
    {
        printf("No children to waiting for\n");
    }
    return 0;
}