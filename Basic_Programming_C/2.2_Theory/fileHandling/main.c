#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fptr;
    fptr = fopen("readtest.txt", "r");
    char ch;
    char myBuffer[100];
    int i_char = 1;
    int i_words = 1;

    while(fgetc(fptr) != EOF)
    {
        ch = fgetc(fptr);
        if(ch ==' ' || ch == '\n')
        {
            i_words++;
        }
        else i_char++;
    }

    printf("The number of WORDS in file: %d\n", i_words);
    printf("The number of CHARS in file: %d\n", i_char);

    fclose(fptr);

    return 0;
}
