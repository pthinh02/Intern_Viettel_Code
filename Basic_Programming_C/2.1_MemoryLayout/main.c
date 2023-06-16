#include <stdio.h>
#include <stdlib.h>

int myfunction(int counter)
{
    int result = 5;
    printf("myfunction %p %p %p \n", &result,&counter, __builtin_frame_address(0));// __builtin_frame_address return adrress of this function frame.
}


int main(int argc, char **argv)
{
    int i; 

    myfunction(5);

    printf("main %p %p \n", &i, __builtin_frame_address(0));

    return 0;
}