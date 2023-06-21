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
    int sockfd,portno,n,i;
    char buffer[256],buffer1[255];
    struct sockaddr_in serv_addr;
    portno=atoi(argv[1]);

    sockfd=socket(AF_INET,SOCK_STREAM,0);

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(portno);
    serv_addr.sin_addr.s_addr=INADDR_ANY;

    // bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

    connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

    printf("Enter the number of inputs : ");
    scanf("%d",&i);
    n=write(sockfd,&i,sizeof(i));
    int no=0;
    while(1){
        printf("Enter the data : \t");
        scanf("%s",buffer);
        n = write(sockfd,buffer,255);
		printf("the message is : %s\n",buffer);
		n = read(sockfd,buffer1,255);
		printf("the reply is : %s\n",buffer1);
		if(strcmp("ACKNOWLEDGEMENT",buffer1)==0){
			no++;
			
		}
        if(no==i){
            break;
        }
    }
    n = read(sockfd,buffer1,255);


}