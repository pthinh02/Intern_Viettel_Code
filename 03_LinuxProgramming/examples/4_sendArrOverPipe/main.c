#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>



int main (int argc, char* argv[])
{
    int arr[6] = { 1,2,3,5,2,9};
    int fd[2];
    int sizeArr = sizeof(arr)/sizeof(int);
    int start ,end;


    if(pipe(fd) == -1)
    {
        printf("An error occured when opening the pipe\n");
        return 1;
    }
    pid_t id = fork();
    if (id == 0 )            // Child process
    {   
        close(fd[0]);
        int sum1=0;
        for (int i =0 ; i< 3; i++ )
        {
            sum1+= arr[i];
        }
        write(fd[1], &sum1, sizeof(int));
        printf("Sent half sum of array\n");
        close(fd[1]);
    }
    else if (id != 0)        //Parent process
    {
        close(fd[1]);
        wait(NULL);
        int sum2 =0;
        int result = 0;
        for (int i = 3; i < 6; i++)
        {
            sum2+= arr[i];
        }
        read(fd[0], &result, sizeof(int));
        result += sum2;
        printf("Sum of array after calculating from 2 process : %d\n", result);
        close(fd[0]);
    }


    return 0;
}