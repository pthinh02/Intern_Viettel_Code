#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define THREADS_NUM 10

int primes[10] = {9, 2, 3, 5, 23, 14, 22, 31, 1, 10};
pthread_t threads[10];

void *routine(void *arg)
{
    sleep(1);
    int j = *(int*)arg;
    printf("[%p]primes[%d] = %d\n",&threads[j], j,primes[j] );
    free(arg);
} 


int main(int argc, char *argv[])
{
    
    srand(time(NULL));
    // int index = rand()%10;
    // int *pointer = &index;
    int i;
    for( i = 0; i <THREADS_NUM; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        if(pthread_create(&threads[i], NULL, &routine , a))
        {
            perror("Failed to create thread\n");
            exit(1);
        }
    }
    for( i = 0; i <THREADS_NUM; i++)
    {
        if(pthread_join(threads[i],NULL))
        {
            perror("Failed to execute thread\n");
            exit(2);
        }
    }
    

    
    return 0;
}