#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>

int main (int argc, char* argv[])
{
    int status = 0;
    int pid1 = fork();

    if(pid1 == 0)       //child process
    {
        printf("My process ID: %d. Going to sleep 5s.\n", getpid());
        sleep(5);
        while(1);
        printf("[%d] WOKE UP\n", getpid());
        exit(EXIT_SUCCESS);
    }
    else if( pid1 != 0)
    {
        while(1)
        {
            int w = waitpid(-1, &status, WNOHANG);
            
            if (w > 0)      //Wait some process
            {
                if(WIFEXITED(status))
                {
                    printf("Exited Normally, status = [%d]\n", WEXITSTATUS(status));
                    break;
                }
                else if(WIFSIGNALED(status))
                {
                    printf("Exited abnormally, status = [%d]\n", WTERMSIG(status));
                    break;
                }
                else if(WIFSTOPPED(status))
                {
                    printf("STOPPED, status = [%d]\n", WSTOPSIG(status));
                    break;
                }
                else if(WIFCONTINUED(status))
                {
                    printf("CONTINUED\n");
                    break;
                }
            }
        }
    }
    
    


    return 0;
}