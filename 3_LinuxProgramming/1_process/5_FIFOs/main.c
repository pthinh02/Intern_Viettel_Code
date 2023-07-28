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

//FIFO same as pipe but for 2 process not in hierachy




int main (int argc, char* argv[])
{
    if(mkfifo("myfifo1", 0777) == -1)   //Create FIFO file
    {
        if(errno != EEXIST)
        {
            printf("Could not create FIFO file\n");
            return 1;
        }
    }
    printf("Opening...");
    int fd = open("myfifo1", O_WRONLY);
    printf("\nOpened succesfully...");

    char buf[16] = "My string\n";
    write(fd, &buf, sizeof(buf));
    printf("\nWriting...");
    close(fd);
    printf("\nClosed successfully...");
    return 0;
}