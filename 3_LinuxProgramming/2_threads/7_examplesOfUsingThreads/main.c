#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define THREADS_NUM 2

int primes[10] = {9, 2, 3, 5, 23, 14, 22, 31, 1, 10};
int globalSum;
int result;

void *routine(void *arg)
{
    int ptr = *(int*)arg;
    int sum = 0;
    for(int j = 0; j < 5; j ++)
    {
        sum += primes[ptr +j];
    }
    *(int*)arg = sum;
    return arg;
}


int main(int argc, char *argv[])
{
    pthread_t threads[THREADS_NUM];


    for(int i = 0; i < THREADS_NUM ; i++)
    {
        int *a= malloc(sizeof(int));
        *a = i*5;

        if(pthread_create(&threads[i], NULL, &routine, a))
        {
            perror("Failed to created threads\n");
        }
    }
    for(int i = 0; i < THREADS_NUM ; i++)
    {
        int *r = malloc(sizeof(int));
        if(pthread_join(threads[i], (void*)&r))
        {
            perror("Failed to join threads\n");
        }
        globalSum += *r;
        free(r);
    }
    printf("Result = %d\n", globalSum);
    


    
    return 0;
}