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
#define PORT 8080
#define MAX_SIZE_BUFFER 1024;



int ret;



int main()
{
    int clientfd = -1;
    char buffer[MAX_SIZE_BUFFER] = {0};

    struct sockaddr_in server_addr = {0};


    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    clientfd = (AF_INET, SOCK_STREAM, 0);





    return 0;
}