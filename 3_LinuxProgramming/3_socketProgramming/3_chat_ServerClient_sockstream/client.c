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
} while(0)                                              \

#define MAX_SIZE_BUFFER 1024
#define PORT 8080

char empty_string[MAX_SIZE_BUFFER];

int main ()
{
    //Declaration variables
    int ret;
    int clientfd = -1;
    char buffer[MAX_SIZE_BUFFER];

    struct sockaddr_in server_addr;

    memset(buffer, 0, sizeof(buffer));

    memset(&server_addr, 0, sizeof(server_addr));
    memset(empty_string, 0, sizeof(empty_string));

    //Create stream socket
    clientfd = socket(AF_INET, SOCK_STREAM, 0);
    
    //Define server address

    server_addr.sin_family =AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);


    ret = connect(clientfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    ERROR_CHECK(ret, "connect()");
    while(1)  
    {   
        memset(buffer, 0, sizeof(buffer));
        

        ret = read(clientfd, buffer, sizeof(buffer));
        ERROR_CHECK(ret, "read()");
        if(ret != -1)
        {
            printf("[+] Server: %s", buffer);
            if(strncmp(buffer, "off",3) == 0)
            {
                break;
            }
        }
        printf("[=] Client: ");
        fgets(buffer, sizeof(buffer), stdin);
        
        ret = write(clientfd, buffer, sizeof(buffer));
        ERROR_CHECK(ret, "write()");

        if(strncmp(buffer, "off", 3) == 0)
        {
            break;
        }
    };
    close(clientfd);

    return 0;
}