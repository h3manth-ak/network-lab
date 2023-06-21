#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>

void main(int argc ,char* argv[]){
    int serv_sockfd,portno,client,newsockfd,n;
    char buffer[256]={0};
    portno=atoi(argv[1]);
    struct sockaddr_in serv_addr,client_addr;


    serv_sockfd=socket(AF_INET,SOCK_STREAM,0);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(portno);
    serv_addr.sin_addr.s_addr=INADDR_ANY;

    bind(serv_sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    listen(serv_sockfd,5);
    client=sizeof(client_addr);
    newsockfd=accept(serv_sockfd,(struct sockaddr *)&client_addr,&client);


    n=read(newsockfd,&i,sizeof(i));
    printf("%s",buffer);
    

}