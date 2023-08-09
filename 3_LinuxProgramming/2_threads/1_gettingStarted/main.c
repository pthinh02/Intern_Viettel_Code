#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 0;

void *routine()
{
    printf("My Process ID is %d.\n", getpid());
    x++;
    printf("[%p] = %d\n",&x, x);
}
void *routine2()
{
    sleep(1);
    printf("My Process ID is %d.\n", getpid());
    x++;
    printf("[%p] = %d\n",&x, x);
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