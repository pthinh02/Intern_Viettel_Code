#include <stdio.h>
#include <stdlib.h>

/*============PASSING FUNCTION POINTER=================*/

int sum(int a, int b)
{
    return a+b;
}

int (*fptrOperator) (int, int);

int calculate(int (*operator)(int,int), int c, int d)
{
    return operator(c,d);
}

int main(int argc, char *argv[])
{
    int (*fptrOperator)(int,int) = &sum;   
    printf("sum = %d\n",  calculate((*fptrOperator), 5,7) );
    return 0;
}
