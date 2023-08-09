#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int mails;

void *routine()
{
    for(int i = 0; i< 100; i++)
    {
        mails ++;
    }
    printf("%d\n", mails);
}


int main()
{
    pthread_t t1, t2;

    if(pthread_create(&t1, NULL, &routine, NULL))
    {
        exit(1);
    }
    if(pthread_create(&t2, NULL, &routine, NULL))
    {
        exit(2);
    }
    if(pthread_join(t1, NULL))
    {
        exit(3);
    }
    if(pthread_join(t2, NULL))
    {
        exit(4);
    }
    return 0;
}