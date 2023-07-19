#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//Viet chuong trinh hien thi noi dung file.(# cat)
//Hint: folder /proc

int main()
{
    int fd;
    char filepath[256];
    char my_buffer[512];
    printf("Enter Filepath: ");
    fgets(filepath, 256, stdin);
    filepath[strcspn(filepath, "\n")] = 0;

    fd  = open(filepath, O_RDONLY);
    if(fd == -1)
    {
        printf("Open failed\n");
        exit(0);
    }
    read(fd, my_buffer, 512);
    printf("%s\n",my_buffer);
    
    

    
    close(fd);

    return 0;
}