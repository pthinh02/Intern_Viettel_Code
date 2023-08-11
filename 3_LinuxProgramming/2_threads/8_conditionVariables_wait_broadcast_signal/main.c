#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define THREADS_NUM 2

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;

int fuel;

void *car()
{
    pthread_mutex_lock(&mutexFuel);
    if(fuel > 40)
    {
        fuel -= 40;
    }
    printf("Got fuel. Now left: %d\n", fuel);

    pthread_mutex_unlock(&mutexFuel);
}
void *fuel_filling()
{
    for(int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mutexFuel);
        fuel += 15;
        usleep(500000);
        printf("Filling....%d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
    }
}


int main(int argc, char *argv[])
{
    pthread_t th[2];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);
    for(int i = 0; i < 2; i ++)
    {
        if(i == 1)
        {
            if(pthread_create(&th[i], NULL, &car, NULL))
            {
                perror("Failed to create threads\n");
                exit(1);
            }
        }
        else
        {
            if(pthread_create(&th[i], NULL, &fuel_filling, NULL))
            {
                perror("Failed to create threads\n");
                exit(1);
            }
        }        
    }
    for(int i = 0; i < 2; i ++)
    {
        if(i == 1)
        {
            if(pthread_join(th[i], NULL))
            {
                perror("Failed to join threads\n");
                exit(1);
            }
        }
        else
        {
            if(pthread_join(th[i], NULL))
            {
                perror("Failed to join threads\n");
                exit(1);
            }
        }        
    }

    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);
    return 0;
}