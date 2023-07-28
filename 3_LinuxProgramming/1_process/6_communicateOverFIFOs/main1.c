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






int main (int argc, char* argv[])
{
    
    int fd = open("sum", O_RDONLY);
    int rcv_buffer[5];
    for(int i = 0; i<5; i++)
    {
        read(fd, &rcv_buffer[i], sizeof(int));
        printf("%d\t", rcv_buffer[i]);
    }
    printf("\n");
    
    close(fd);


    
    return 0;
}