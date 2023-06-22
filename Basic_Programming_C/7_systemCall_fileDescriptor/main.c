#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

clock_t start;
clock_t end;
double time_used;

int main(void)
{
    start = clock();
    int fd;
    char my_buffer[12] = "Hello World\n";
    fd = open("hello.txt", O_RDWR | O_CREAT , 0666);
    if (fd == -1)
    {
        printf("Open() hello.txt failed.\n");
    }
    write(fd, my_buffer,strlen(my_buffer));

    lseek(fd, 2, SEEK_CUR);
    write(fd, "I Love Viettel", strlen("I Love Viettel"));
    close(fd);
    end = clock();
    time_used = ((double) end - start) / CLOCKS_PER_SEC;
    printf("Time of using System call: %f (sec)\n", time_used);
}


