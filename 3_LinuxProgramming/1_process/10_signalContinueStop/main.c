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
    pid_t pid = fork();

    if(pid == 0) //Child Process
    {
        while(1)
        {
            printf("Hello World\n");
            usleep(500000);
        }
    }
    else        //Parent Process
    {
        int t;
        kill(pid, SIGSTOP);
        do
        {
            printf("Enter second you want: ");
            scanf("%d", &t);
            kill(pid, SIGCONT);
            sleep(t);
            kill(pid, SIGSTOP);
        }while(t>0);


        kill(pid, SIGKILL);
        wait(NULL);
        printf("everythings DONE \n");
    }

    return 0;
}

