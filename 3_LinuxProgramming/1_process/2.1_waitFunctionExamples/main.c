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


int main(int argc, char const *argv[])   
{
    
    pid_t child_pid;                
    int status, rv;

    child_pid = fork();         
    if (child_pid >= 0) {
        if (0 == child_pid) {       /* Child Process */
            printf("Im the child process, my PID: %d\n", getpid());
            // sleep(3);
            while(1){};

        } else {                     /*Parent Process */
                rv = wait(&status);
                if (rv == -1) {
                    printf("wait() unsuccessful\n");
                }

                printf("\nIm the parent process, PID child process: %d\n", rv);
                
                if (WIFEXITED(status)) {
                    printf("Normally termination, status=%d\n", WEXITSTATUS(status));
                } else if (WIFSIGNALED(status)) {
                    printf("killed by signal, value = %d\n", WTERMSIG(status));
                } 
        }
    } else {
        printf("fork() unsuccessfully\n");  
    }

    return 0;
}
