#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>


#define ERROR_CHECK(ret, msg)                           \
do{                                                     \
    if(ret == -1)                                       \
    {                                                   \
        fprintf(stderr, "%s[%d]", __FILE__, __LINE__);    \
        perror(msg);                                    \
        exit(EXIT_FAILURE);                              \
    }                                                   \
}while(0);                                              \


int main()
{

    return 0;
}