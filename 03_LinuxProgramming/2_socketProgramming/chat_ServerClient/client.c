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

#define ERROR_CHECK(ret, msg)						    \
do{	                                                    \
	if((ret) == -1)								        \
	{											        \
		fprintf(stderr, "%s[%d] ", __FILE__, __LINE__);	\
		perror(msg);						            \
		exit(EXIT_FAILURE);						        \
	}											        \
} while(0)

#define MAX_SIZE_BUFFER 1024
#define PORT 8080



int main ()
{
    int ret;
    int clientfd = -1;
    char send_msg[MAX_SIZE_BUFFER];
    char recv_msg[MAX_SIZE_BUFFER];

    struct sockaddr_in server_addr;

    memset(send_msg, 0, sizeof(send_msg));
    memset(recv_msg, 0, sizeof(recv_msg));
    memset(&server_addr, 0, sizeof(server_addr));

    clientfd = socket(AF_INET, SOCK_STREAM, 0);
    
    server_addr.sin_family =AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    //bind(clientfd, (struct sockaddr*) &server_addr, sizeof(server_addr));

    ret = connect(clientfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    ERROR_CHECK(ret, "connect()");
    do   
    {         
        read(clientfd, recv_msg, sizeof(recv_msg));
        printf("[+] Server: %s\n", recv_msg);
        
    }while( !(recv_msg[0] == 'O')&&(recv_msg[1] == 'F')&&(recv_msg[2] == 'F') && (ret == 0) );
    close(clientfd);

    return 0;
}