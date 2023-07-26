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

int main(int argc, char* argv[])
{
    int p1[2];
    if(pipe(p1) == -1)
    {
        return 1;
    }

    int pid = fork();
    if(pid == -1)
    {
        printf("Fork failed\n");
        return 2;
    }
    if(pid == 0) // child process
    {
        close(p1[1]);
        int x;
        read(fd[0], &x, sizeof(int));
        close(p1[0]);

    }
    else if( pid != 0)
    {

    }


    return 0;
}