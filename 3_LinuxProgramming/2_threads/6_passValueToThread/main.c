#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>


int primes[10] = {9, 2, 3, 5, 23, 14, 22, 31, 1, 10};

void *routine()
{
    
}


int main(int argc, char *argv[])
{
    srand(time(NULL));

    pthread_t t1;

    if(pthread_create(&t1, NULL, &roll_dice, NULL))
    {
        perror("Failed to create thread\n");
        exit(1);
    }
    if(pthread_join(t1,NULL)
    {
        perror("Failed to execute thread\n");
        exit(2);
    }

    

    
    return 0;
}