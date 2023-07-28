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
}while(0);                                          \

int main(int argc, char *argv[])
{
    int clientfd;
    int ret;
    char buffer[] = "VIETTEL123";


    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));

    //Create a socket
    clientfd = socket(AF_INET, SOCK_DGRAM, 0);

    //Define server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");


    ret = sendto(clientfd, buffer, sizeof(buffer),
           0, (struct sockaddr*) &server_addr,
           sizeof(server_addr));
    ERROR_CHECK(ret, "sendto()");



    close(clientfd);

    return 0;
}









