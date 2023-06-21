#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>

void main(int argc ,char* argv[]) {
    int sockfd,portno,n;
    struct sockaddr_in serv_addr;
    char buffer[256];
    portno=atoi(argv[1]);
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    printf("%d\n",sockfd);

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(portno);
    serv_addr.sin_addr.s_addr=INADDR_ANY;
    connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    n=write(sockfd,"buffer",24);
    
}