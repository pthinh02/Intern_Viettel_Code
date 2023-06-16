#include <stdio.h>

void main(int argc, char **argv)
{
    printf("So doi so truyen vao: %i \n", argc);
    printf("Gia tri cac doi so: ");
    for(int i = 0; i<argc; i++)
    {
        printf("%s\t", argv [i]);
    }
    printf("\n");

}