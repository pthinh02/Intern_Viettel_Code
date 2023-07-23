#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>

char *msg = "Hello viettel #1\n";
char *msg2 = "Hello viettel #2\n";
char *msg3 = "Hello viettel #3\n";

char myBuf[256];

int main (int argc, char* argv[])
{
    int fd[2];
    // fd[0] => read; fd[1] => write
    if(pipe(fd) == -1)
    {
        printf("An error occur with opening the pipe\n");
        return 1;
    }

    pid_t id = fork();
    if(id == 0) //Child process
    {
        close (fd[0]);
        // int x;
        // printf("Enter a number: ");
        // scanf("%d", &x);
        write(fd[1], msg, sizeof(myBuf));
        write(fd[1], msg2, sizeof(myBuf));
        write(fd[1], msg3, sizeof(myBuf));
        close(fd[1]);
        printf("Succesful!\n");

    }
    else        //Parent process
    {
        close (fd[1]);
        wait(NULL);
        for (int i = 0; i< 3; i++)
        {
            read(fd[0], &myBuf, 256);
            printf("Read number from child process: %s\n", myBuf);
        }
        close(fd[0]);
    }



    return 0;
}