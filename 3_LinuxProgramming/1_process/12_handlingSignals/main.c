#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


void handle_sigtstp(int sig)
{
    printf("\nStop not allowed\n");
    
}
void handle_sigcont(int sig)
{
    printf("Input a number: ");
    fflush(stdout);
}

int main()
{
    struct sigaction sa1, sa2;  //sa1 = sigtstp; sa2 = sigcont

    // sa1.sa_handler = &handle_sigtstp;
    // sa1.sa_flags = SA_RESTART;

    sa2.sa_flags = SA_RESTART;
    sa2.sa_handler = &handle_sigcont;

    sigaction(SIGCONT, &sa2, NULL);
    // sigaction(SIGTSTP, &sa2, NULL);

    // signal(SIGTSTP, &handle_sigtstp);


    int x;
    printf("Input a number: ");
    scanf("%d", &x);
    printf("%d x 4 = %d\n", x, x*4);



    return 0;
}