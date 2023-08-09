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


#define MAX_SIZE_BUFFER 1024
#define BACK_LOG 50
#define PORT 8080

#define ERROR_CHECK(ret,msg)                        \
do{                                                 \
if(ret == -1){                                      \
    fprintf(stderr, "%s[%d]", __FILE__, __LINE__);  \
    perror(msg);                                    \
    exit(EXIT_FAILURE);                             \
}                                                   \
}while(0);                                           \

int main(int argc, int *argv[])
{
    int serverfd = -1;
    int ret;

    struct sockaddr_in server_addr;

    char buffer[MAX_SIZE_BUFFER];

    memset(&server_addr, 0 , sizeof(server_addr));

    serverfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(serverfd == -1)
    {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;


    ret = bind(serverfd, (struct sockaddr*) &server_addr, sizeof(server_addr));
    ERROR_CHECK(ret, "bind()");

    ret = recvfrom(serverfd, buffer, sizeof(buffer), 0,
            (struct sockaddr*) NULL,
           NULL);
    ERROR_CHECK(ret, "recvfrom()");


    printf("%d %s\n", ret, buffer);
    close(serverfd);
    return 0;
}