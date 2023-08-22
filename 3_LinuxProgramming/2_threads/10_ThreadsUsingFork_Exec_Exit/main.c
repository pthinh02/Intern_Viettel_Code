#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h>

#ifndef SYS_gettid
#error "SYS_gettid unavailable on this system"
#endif

#define gettid() ((pid_t)syscall(SYS_gettid))

int x = 0;

void *routine()
{
    printf("[1]Process ID of Thread 1 is %d.\n", getpid());
    pid_t id = fork();
    if( id == 0 )       //Child Process
    {
        printf("[1]Child process ID in thread 1 = %d\n", getpid());
    }
    else
    {
        printf("[1]Child process ID in thread 2 = %d\n", getpid());
    }
    
}
void *routine2()
{
    printf("[2]Process ID of Thread 2 is %d.\n", getpid());
    sleep(1);

    printf("[2] thread ID is %d\n",gettid());
    printf("[2] process ID is %d\n",getpid());
}


int main(int argc, char* argvp[])
{
    pthread_t  t1, t2;
    if( pthread_create(&t1, NULL, &routine, NULL))
    {
        exit(1);
    }

    if( pthread_create(&t2, NULL, &routine2, NULL))
    {
        exit(1);
    }

    if( pthread_join(t1, NULL))
    {
        exit(2);
    }
    
    if( pthread_join(t2, NULL))
    {
        exit(2);
    }



    return 0;
}