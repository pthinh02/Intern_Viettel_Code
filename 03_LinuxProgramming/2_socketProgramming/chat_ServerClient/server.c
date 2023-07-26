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
#define PORT 8080

int main()
{
    int listenfd = -1;
    int p2pfd = -1;
    struct sockaddr_in server_addr, client_addr;
    int client_addr_len = sizeof(client_addr);

    char send_msg[MAX_SIZE_BUFFER];
    char recv_msg[MAX_SIZE_BUFFER];
    
    memset(recv_msg, 0, sizeof(recv_msg));
    memset(send_msg, 0, sizeof(send_msg));
    memset(&server_addr, 0, sizeof(server_addr));

    listenfd = socket(AF_INET,SOCK_STREAM, 0 );
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; //inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    bind(listenfd, (struct sockaddr*) &server_addr, sizeof(server_addr));
    listen(listenfd, 50);
    
    while(1)
    {
        p2pfd = accept(listenfd, (struct sockaddr*) &client_addr, &client_addr_len);
        printf("Enter something: ");
        fgets(send_msg, sizeof(send_msg), stdin);
        write(p2pfd, send_msg, strlen(send_msg));
        close(p2pfd);
    }
    close(listenfd);


    return 0;
}