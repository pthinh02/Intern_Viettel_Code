#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#define ERROR_CHECK(ret, msg)                           \
do{                                                     \
    if(ret == -1){                                      \
        fprintf(stderr, "%s[%d]", __FILE__, __LINE__);  \
        perror(msg);                                    \
        exit(EXIT_FAILURE);                             \
    }                                                   \             
}while(0);                                              \

int x = 0;
int ret = 0;

void handle_sigusr1(int sig)
{
    if(x == 0)
    {
        printf("\nRemember about multiplication table\n");
        // fflush(stdout);
        printf("What is the result of 3 x 5 = ");       //there is a bug right here
    }
}


int main( int argc, char* argv[])
{
    pid_t pid = fork();
    ERROR_CHECK(pid, "fork()");

    if( pid == 0)
    {   //Child process
        sleep(5);
        kill(getppid(), SIGUSR1);
    }
    else 
    {   //Parent process
        
        //Declare signal action
        struct sigaction sa = {0};
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &handle_sigusr1;
        sigaction(SIGUSR1, &sa, NULL);


        
        printf("What is the result of 3 x 5 = ");
        scanf("%d", &x);
        if( x == 15 )
        {
            printf("Right!\n");
        }
        else {
            printf("Wrong!\n");
        }
        wait(NULL);
    }

    return 0;
}