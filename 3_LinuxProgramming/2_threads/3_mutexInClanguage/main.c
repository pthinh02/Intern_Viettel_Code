#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int mails;
pthread_mutex_t mutex;
void *routine()
{
    for(int i = 0; i < 100000000; i++ )
    {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t t1,t2;
    pthread_mutex_init(&mutex, NULL);


    if(pthread_create(&t1, NULL, &routine, NULL))
    {
        return 1;
    }
    if(pthread_create(&t2, NULL, &routine, NULL))
    {
        return 2;
    }
    if(pthread_join(t1, NULL))
    {
        return 3;
    }
    if(pthread_join(t2, NULL))
    {
        return 4;
    }
    pthread_mutex_destroy(&mutex);

    printf("Number of mails: %d\n", mails);
    return 0;
}