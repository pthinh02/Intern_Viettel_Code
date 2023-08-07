#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// If you want to bring process from bg to foreground => using fg command.



int main(int argc, char* argv[])
{
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    printf("%d x %d = %d", x,x,x*x);

    return 0;
}