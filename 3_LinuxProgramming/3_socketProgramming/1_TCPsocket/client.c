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

int main()
{
    int clientfd = -1;
    struct sockaddr_in server_addr;
    char recv_buffer[1024];
    time_t ticks;

    memset(recv_buffer,0,sizeof(recv_buffer));
    memset(&server_addr,0,sizeof(server_addr));

    clientfd = socket(AF_INET, SOCK_STREAM, 0);
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(4455);
    
    bind(clientfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(connect(clientfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0)
    {
        read(clientfd, recv_buffer, sizeof(recv_buffer));
        printf("\n%s\n", recv_buffer);
        
    }
    close(clientfd);
    return 0;
}