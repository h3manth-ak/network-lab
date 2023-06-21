#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>
#include<sys/wait.h>

void main(int argc,char * argv[]){
    int portno,serv_sockfd,newsockfd,n,i;
    char buffer[256],buffer1[255]="ACKNOWLEDGEMENT",buffer2[255]="no";
    struct sockaddr_in serv_addr,client_addr;

    portno=atoi(argv[1]);
    serv_sockfd=socket(AF_INET,SOCK_STREAM,0);

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(portno);
    serv_addr.sin_addr.s_addr=INADDR_ANY;

    bind(serv_sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    listen(serv_sockfd,5);
    int clilen=sizeof(client_addr);
    newsockfd=accept(serv_sockfd,(struct sockaddr *)&client_addr,&clilen);

    n=read(newsockfd,&i,sizeof(i));
    printf("%d",i);

    int no=0;
    int count=0;
    while(1){
        n=read(newsockfd,buffer,sizeof(buffer));
        printf("The msg is -> %s",buffer);
        if(!strcmp(buffer,"3")||!strcmp(buffer,"5")){
            if(count==0){
                sleep(3);
                n=write(newsockfd,buffer2,255);
                count=1;
            }else{
                no++;
                count=0;
                n= write(newsockfd,buffer1,255);
            }
        }else{
            n= write(newsockfd,buffer1,255);
			printf("the ACKNOWLEDGEMENT SEND IS : %s\n",buffer1);
			no++;
			if(no==i){
				break;
			}
        }
    }
    


}
