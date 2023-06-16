#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "include.h"

someone_t arr[MAX_PEOPLE];

int main(int argc, char **argv)
{
    FILE *file_ptr = fopen("output.txt", "a");

    srand(time(NULL));
    int random_number = random_integer(1,MAX_PEOPLE);
    
    fprintf(file_ptr,"\nTHERE ARE %d PEOPLE WAS INITIALIZED.\n", random_number);
    for(int i = 0; i<random_number; i++)
    {
        input(&arr[i]);
    }

    for (int i = 0; i< random_number; i++)
    {
        fprintf(file_ptr,"\n==========================================\n");
        fprintf(file_ptr,"PEOPLE %d\n", i+1);
        output(&arr[i],file_ptr);
        fprintf(file_ptr,"==========================================\n");
    }


    fclose(file_ptr);
	return 0;
}