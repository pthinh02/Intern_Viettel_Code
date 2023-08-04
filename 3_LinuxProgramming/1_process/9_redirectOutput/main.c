#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>

// FIFO lib
#include <sys/stat.h>
#include <sys/types.h>
// system call lib
#include <fcntl.h>




int main()
{
    char* path = "./bangcuuchuong/multiple";
    char* pathPing = "/bin/ping";
    char* arg1 = "4";

    

    pid_t id = fork();
    if(id == 0) //Child process
    {
        int id2 = fork();
        if(id2 == 0)
        {
            int outputfd = open("pingResuslts.txt", O_CREAT | O_WRONLY, 0777);
            if(outputfd == -1)
            {
                printf("Cannot create file Results.\n");
                return 2;
            }

            printf("The file descriptor of pingResults: %d\n", outputfd);
            int outputfd2 = dup2(outputfd, STDOUT_FILENO);
            printf("The file descriptor of duplicated: %d\n", outputfd2);
            int ret = execl(pathPing,pathPing,"-c" , "4", "google.com", NULL);
            if(ret == -1)
            {
                printf("Could not find the program to execute!\n");
                return 2;
            }
        }
        else   //Parent process 
        {
            int wstatus;
            wait(&wstatus);
            if( WIFEXITED(wstatus))
            {
                int statusCode = WEXITSTATUS(wstatus);
                if(statusCode == 0)
                {
                    printf("Success\n");
                }
                else 
                {
                    printf("Failure with status code %d.\n", statusCode);
                }
            }
            wait(NULL);
            printf("Mission completed!\n");
        }
        exit(1);
    }
    else if(id != 0)    // Parent process
    {
        
        wait(NULL);
        printf("Wait for child process\n");
    }

    



    return 0;
}