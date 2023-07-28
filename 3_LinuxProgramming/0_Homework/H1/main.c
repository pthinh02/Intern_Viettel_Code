#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//Viet chuong trinh in ra ten cua process tu ProcessID nhap tu keyboard
//Hint: folder /proc

int main()
{
    pid_t PID; //ProcessID
    int fd;
    char filepath[256];
    char my_buffer[512];
    printf("Enter process id: ");
    scanf("%d", &PID);

    sprintf(filepath, "/proc/%d/cmdline", PID);
    


    fd  = open(filepath, O_RDONLY);
    if(fd == -1)
    {
        printf("Open failed\n");
        exit(1);
    }
    read(fd, my_buffer, 512);
    printf("%s\n",my_buffer);
    
    

    
    close(fd);

    return 0;
}