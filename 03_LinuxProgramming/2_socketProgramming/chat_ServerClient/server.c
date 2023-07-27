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
#define BACKLOG 50

#define ERROR_CHECK(ret, msg)                           \
do{                                                     \
    if(ret == -1)                                       \
    {                                                   \
        fprintf(stderr, "%s[%d]", __FILE__, __LINE__);  \
        perror(msg);                                    \
        exit(EXIT_FAILURE);                             \
    }                                                   \
}while(0);                                              \


int main(int argc, char *argv[])
{
    //Declare
    int listenfd = -1;
    int p2pfd = -1;
    int portno;
    int ret;
    struct sockaddr_in server_addr, client_addr;
    int client_addr_len = sizeof(client_addr);

    char buffer[MAX_SIZE_BUFFER];
    char buffer[MAX_SIZE_BUFFER];
    
    memset(buffer, 0, sizeof(buffer));
    memset(&server_addr, 0, sizeof(server_addr));


    if(argc < 2)
    {
        printf("Please provide input as <filename> <port> <ipaddress> \n");
        exit(1);
    }

    portno = atoi(argv[1]);


    

    //Create a server socket
    listenfd = socket(AF_INET,SOCK_STREAM, 0 );
    
    //Define server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; //inet_addr("127.0.0.1");
    server_addr.sin_port = htons(portno);


    ret = bind(listenfd, (struct sockaddr*) &server_addr, sizeof(server_addr));
    ERROR_CHECK(ret, "bind()");
    
    ret = listen(listenfd, BACKLOG);
    ERROR_CHECK(ret, "listen()");

    p2pfd = accept(listenfd, (struct sockaddr*) &client_addr, &client_addr_len);

    while(1)
    {
        memset(buffer, 0, sizeof(buffer));


        printf("[+] Server: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(p2pfd, buffer, strlen(buffer));

        if(strncmp(buffer, "off", 3) == 0 )
        {
            break;
        }

        ret = read(p2pfd, buffer, strlen(buffer));
        ERROR_CHECK(ret, "read()");
        
        printf("%s", buffer);
        if(strncmp(buffer, "off", 3) == 0 )
        {
            break;
        }
        if(strncmp(buffer, "0", 1) == 0)
        {
            continue;
        }
        printf("[=] Client: %s", buffer);
    };
    close(p2pfd);
    close(listenfd);


    return 0;
}