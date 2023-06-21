#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>

void main(int argc ,char* argv[]){
    int serv_sockfd,clilen,portno,n,rec1,rec2,sen1,k,i,j;
    struct sockaddr_in serv_addr,client_addr;
    
    serv_sockfd=socket(AF_INET,SOCK_DGRAM,0);
    portno=atoi(argv[1]);

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(portno);
    serv_addr.sin_addr.s_addr=INADDR_ANY;

    bind(serv_sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    listen(serv_sockfd,5);
    clilen=sizeof(client_addr);

    rec1=recvfrom(serv_sockfd,&i,sizeof(i),MSG_WAITALL,(struct sockaddr *)&client_addr,&clilen);
    printf("f Num : %d ",i);
    rec2=recvfrom(serv_sockfd,&j,sizeof(j),MSG_WAITALL,(struct sockaddr *)&client_addr,&clilen);
    printf("s Num : %d ",j);


    k=i+j;
    printf("\n sum : %d",k);

    sen1=sendto(serv_sockfd,&k,sizeof(k),MSG_CONFIRM,(struct sockaddr *)&client_addr,sizeof(client_addr));




}