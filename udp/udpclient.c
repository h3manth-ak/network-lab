#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>

void main(int argc ,char* argv[]){
    int sockfd,portno,n,i,j,sum,sen1,sen2,rec1,len;
    struct sockaddr_in serv_addr;

    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    portno=atoi(argv[1]);

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(portno);
    serv_addr.sin_addr.s_addr=INADDR_ANY;

    printf("Enter the first number : ");
    scanf("%d",&i);
    len=sizeof(serv_addr);
    sen1=sendto(sockfd,&i,sizeof(i),MSG_CONFIRM,(const struct sockaddr *) &serv_addr,sizeof(serv_addr));

    printf("Enter the first number : ");
    scanf("%d",&j);    

    sen2=sendto(sockfd,&j,sizeof(i),MSG_CONFIRM,(const struct sockaddr *)&serv_addr,sizeof(serv_addr));

    rec1=recvfrom(sockfd,&sum,sizeof(sum),MSG_WAITALL,(struct sockaddr *)&serv_addr,&len);
    printf("sum : %d",sum);

}