#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>


void *roll_dice()
{
    int value = rand()%6 +1;
    int *result = malloc(sizeof(int));
    *result = value;
    printf("Location of variables: %p\n", result);
    printf("Result : %d\n", *result);
    pthread_exit((void*) result);
}


int main(int argc, char *argv[])
{
    srand(time(NULL));

    int *res;
    pthread_t t1;

    if(pthread_create(&t1, NULL, &roll_dice, NULL))
    {
        perror("Failed to create thread\n");
        exit(1);
    }
    if(pthread_join(t1,(void**) &res))
    {
        perror("Failed to execute thread\n");
        exit(2);
    }

    printf("%p\n", res);
    printf("%d\n", *res);

    free(res);
    return 0;
}