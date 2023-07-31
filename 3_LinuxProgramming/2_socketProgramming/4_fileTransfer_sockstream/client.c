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

void receive_file(int socketfd);

#define BACK_LOG 50
#define MAX_SIZE_BUFFER 1024
#define PORT 8080
int ret;            //test value

int main(int argc, char* argv[])
{
    
    int clientfd = -1;

    int buffer[MAX_SIZE_BUFFER];
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    memset(buffer, 0, sizeof(buffer));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;


    clientfd = socket(AF_INET, SOCK_STREAM, 0);

    ret = connect(clientfd, (struct sockaddr*) &server_addr, sizeof(server_addr));
    ERROR_CHECK(ret, "connect()");

    receive_file(clientfd);


    return 0;
}



void receive_file(int socketfd)
{
    int fd;

    fd = open("Rtext.txt", O_RDWR | O_CREAT, 0666);

    while(1)
    {

        char buffer[MAX_SIZE_BUFFER] ={0};
        ret = recv(socketfd, buffer, MAX_SIZE_BUFFER, 0);
        ERROR_CHECK(ret, "recv()");
        
        write(fd, buffer, sizeof(buffer));
        close (socketfd);
    }

}