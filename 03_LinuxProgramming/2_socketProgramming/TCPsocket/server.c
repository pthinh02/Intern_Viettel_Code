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
    int listenfd = -1;          //dung de listen ban tin yeu cau ket noi
    int connfd = -1;            //socket de giao tiep p2p ung voi moi client
    struct sockaddr_in server_addr;
    char send_buffer[1024];
    time_t ticks;

    memset(send_buffer,0,sizeof(send_buffer));
    memset(&server_addr, 0, sizeof(server_addr));

   listenfd = socket(AF_INET, SOCK_STREAM, 0);
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
   server_addr.sin_port = htons(4455);

   bind(listenfd, (struct sockaddr*) &server_addr, sizeof(server_addr));
   listen(listenfd, 10);

   while(1)
   {
      connfd = accept(listenfd, (struct sockaddr*) NULL, NULL);
      ticks = time(NULL);
      sprintf(send_buffer, "Server reply at: %s", ctime(&ticks));
      write(connfd, send_buffer, sizeof(send_buffer));
      close(connfd);
   }
    close(listenfd);
    return 0;
 }