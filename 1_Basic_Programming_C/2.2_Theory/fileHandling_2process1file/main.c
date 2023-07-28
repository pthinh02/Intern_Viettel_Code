#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char myBuffer;

int main(int argc, char **argv)
{
    
    FILE *fptr;
    fptr = fopen("common.txt", "w");
    
    
    char somechar= 'y';
    
    while((somechar == 'y'))
    {
        printf("Nhap vao ky tu: ");
        scanf("%c", &(myBuffer));
        fprintf(fptr,"%c", myBuffer);
        fgetc(stdin);
        printf("\nDo you want continue(y/n): ");
        somechar = fgetc(stdin);
        fgetc(stdin);
        fseek(fptr,4,SEEK_END);
    }


    fclose(fptr);

    return 0;
}
