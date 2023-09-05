#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>

int main (int argc, char* argv[])
{
    pid_t child_pid;               
    int status;

    child_pid = fork();         
    if (child_pid >= 0) {
        if (0 == child_pid) {       /* Process Child */
            printf("Im the child process, my PID: %d\n", getpid());
            exit(EXIT_SUCCESS);

        } else {                    /* Process Parent */
            while(1);  
            wait(&status);
            
        }
    } else {   
        printf("fork() unsuccessfully\n"); 
    }



    return 0;
}