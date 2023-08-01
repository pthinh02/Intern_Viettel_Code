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
    int fd1[2];     //C => P
    int fd2[2];     //P => C



    if( (pipe(fd1) == -1) || pipe(fd2) == -1 )
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
        close(fd1[0]);
        close(fd2[1]);
        int x;
        if( read(fd2[0], &x, sizeof(int)) == -1) { return 3; }
        x *= 4;
        printf("CHILD: received %d\n",x);
        if( write(fd1[1], &x, sizeof(x)) == -1 ) { return 4;}
        printf("CHILD: sent %d\n", x);
    }
    else if( pid != 0)
    {
        // parent process
        close(fd1[1]);
        close(fd2[0]);
        int y;
        srand(time(NULL));
        y = rand()  %10;
        if(write(fd2[1], &y, sizeof(y)) == -1 ) {return 5;}
        printf("PARENT: Sent %d \n", y);
        if(read(fd1[0], &y, sizeof(y)) == -1 ) {return 6; }
        printf("PARENT: received %d\n", y);

    }
    close(fd1[0]);
    close(fd1[1]);
    close(fd2[0]);
    close(fd2[1]);
    return 0;
}