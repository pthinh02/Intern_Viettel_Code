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
    char* arg1 = "4";

    pid_t id = fork();
    if(id == 0) //Child process
    {
        int id2 = fork();
        if(id2 == 0)
        {
            execlp(path,path, arg1, NULL);
        }
        else 
        {
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