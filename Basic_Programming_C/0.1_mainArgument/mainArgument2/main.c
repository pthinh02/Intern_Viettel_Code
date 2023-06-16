#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int auth_flag = 0;


void check_authentication( char *password )
{
    char buffer[16];   
    strcpy(buffer,password);
    if (strcmp(buffer,"liverpool") == 0)
    {
        auth_flag = 1;
    }
    else auth_flag = 0;
    
}

int main (int argc, char * argv[])
{
    if (argc < 2)
    {
        printf("\nPLEASE ENTER PASSCODE\n");
        exit(0);
    }
    
    check_authentication(argv[1]);

    if (auth_flag)
    {   
        printf("\nACCESS COMPLETED\n");
    }
    else printf("\nWRONG PASSWORD\n");

    return 0;
}