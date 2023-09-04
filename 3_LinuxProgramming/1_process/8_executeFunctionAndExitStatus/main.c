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


// p1[0] = read()
// p1[1] = write()

int main()
{
    char* path = "./bangcuuchuong/multiple";
    char* pathPing = "/bin/ping";
    char* arg1 = "4";

    pid_t id = fork();
    if(id == 0) //Child process
    {
        int id2 = fork();
        if(id2 == 0)    //Grand child process was replaced by exec()
        {
            int ret = execlp("ping","ping","-c" , "4", "google.com", NULL);
            if(ret == -1)
            {
                printf("Could not find the program to execute!\n");
                return 2;
            }
        }
        else            //Check information return of child process
        {
            int wstatus;
            wait(&wstatus); //Status of child process return
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
    else if(id != 0)    // Parent process waiting for child process
    {
        wait(NULL);
        printf("Wait for child process\n");
    }

    



    return 0;
}