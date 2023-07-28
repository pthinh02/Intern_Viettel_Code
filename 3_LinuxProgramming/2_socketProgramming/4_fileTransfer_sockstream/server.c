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

#define ERROR_CHECK(ret, msg)                           \
do{                                                     \
    if(ret == -1)                                       \
    {                                                   \
        fprintf(stderr, "%s[%d]", __FILE__, __LINE__);    \
        perror(msg);                                    \
        exit(EXIT_FAILURE);                              \
    }                                                   \
}while(0);                                              \


#define BACK_LOG 50
#define MAX_SIZE_BUFFER 1024
#define PORT 8080

void send_file(int socketfd, int filefd );


int main(int argc, char* argv[])
{
    int listenfd = -1;
    int p2pfd = -1;
    int ret;
    FILE* fp;
    

    char filename[100] = "./mytext.txt";

    fp = open(filename, O_RDWR | O_CREAT, 0666);

    struct sockaddr_in server_addr, client_addr;

    char buffer[100];


    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("[+] Server: Socket created.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    ret = bind(listenfd, (struct sockaddr*) &server_addr, sizeof(server_addr));
    ERROR_CHECK(ret,"bind()");
    printf("[+] Server: Binding successfull.\n");

    ret = listen(listenfd, BACK_LOG);
    ERROR_CHECK(ret, "listen()");
    printf("[+] Server: Listening.......\n");

    p2pfd = accept(listenfd, (struct sockaddr*) NULL,NULL);

    send_file(p2pfd, fp);
    printf("Send success\n");
    return 0;
}



void send_file(int socketfd, int filefd)
{
    buffer[MAX_SIZE_BUFFER]= {0};
    while( fgets(buffer, MAX_SIZE_BUFFER, filefd) != NULL)
    {
        if ( send (socketfd, buffer, sizeof(buffer) , NULL) == -1 )
        {
            perror("Error in sending data\n");
            exit(1);
        }
        memset(buffer,0, MAX_SIZE_BUFFER);
    }

}