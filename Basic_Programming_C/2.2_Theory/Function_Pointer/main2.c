#include <stdio.h>
#include <stdlib.h>

/*============ARRAY FUNCTION POINTER=================*/

int sum(int a,int b)
{
    return a+b;
}
int minus(int a, int b)
{
    return a-b;
}
int  multiple(int a,int b)
{
    return a*b;
}

int (*afptr[])(int,int) = {
    &sum,
    &minus,
    &multiple
};

int main(int argc, char *argv[])
{   
    int a = 4;
    int b = 5;
    printf("\nsum of a +b = %d\n",  (*afptr[0])(a,b));
    return 0;
}

