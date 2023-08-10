#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define THREADS_NUM 4

int mails;
pthread_mutex_t mutex;
void *routine()
{
    for(int i = 0; i < 1000000; i++ )
    {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t threads[THREADS_NUM];
    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i< THREADS_NUM; i++)
    {
        if(pthread_create(&threads[i], NULL, &routine, NULL))
        {
            perror("Failed to create threads\n");
            return 1;
        }
        printf("Thread %d has created\n", i);
    }

    for(int i = 0; i< THREADS_NUM; i++)
    {
        if(pthread_join(threads[i], NULL))
        {
            perror("Failed to join threads\n");
            return 2;
        }
        printf("Thread %d has finished exection\n",i);
    }
    
    
    
    pthread_mutex_destroy(&mutex);

    printf("Number of mails: %d\n", mails);
    return 0;
}