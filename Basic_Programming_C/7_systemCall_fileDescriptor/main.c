#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    int numb_write;
    char my_buffer[12] = "Hello World\n";
    fd = open("hello.txt", O_RDWR | O_CREAT , 0666);
    if (fd == -1)
    {
        printf("Open() hello.txt failed.\n");
    }
    numb_write = write(fd, my_buffer,strlen(my_buffer));
    printf("Write %d bytes to hello.txt", numb_write);
    lseek(fd, 2, SEEK_CUR);
    write(fd, "I Love Viettel", strlen("I Love Viettel"));
    close(fd);
}


