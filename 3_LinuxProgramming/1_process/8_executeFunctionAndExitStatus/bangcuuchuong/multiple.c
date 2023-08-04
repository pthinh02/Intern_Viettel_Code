#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {  
        perror("Shortage of arguments");
        exit(EXIT_FAILURE);
    }
    int x = atoi(argv[1]);
    for( int i = 1; i<11; i++ )
    {
        printf("\t%d x %d = %d\n", x,i,x*i);
    }
    

    return 0;
}
