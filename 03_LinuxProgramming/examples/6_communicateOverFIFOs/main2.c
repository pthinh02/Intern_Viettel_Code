#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
// FIFO lib
#include <sys/stat.h>
#include <sys/types.h>
// system call lib
#include <fcntl.h>

int randomN(int minN, int maxN)
{
    return (minN + rand() %(maxN - minN +1));
}




int main (int argc, char* argv[])
{
    srand((int)time(0));
    int send_arr[5];

    int fd = open("sum", O_WRONLY);

    for(int i = 0; i< 5; i++)
    {
        send_arr[i] = randomN(1,10);
    }

    for(int i = 0; i<5; i++)
    {
        write(fd,&send_arr[i],sizeof(int));
        printf("%d\t", send_arr[i]);
    }
    printf("\n");
    close(fd);
    return 0;
}