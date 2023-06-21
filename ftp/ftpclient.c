#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>

void main(int argc,char* argv[]){
    int portno,sockfd,n;
    struct sockaddr_in serv_addr;
    char command[50]={0},filename[20]={0},buffer[1024]={0};
    
    portno=atoi(argv[1]);

    sockfd=socket(AF_INET,SOCK_STREAM,0);

    serv_addr.sin_family=AF_INET;
	serv_addr.sin_port =htons(portno);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

    connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

    printf("Enter the command [GET/PUT] : ");
    scanf("%s",command);
    n=write(sockfd,command,sizeof(command));
    printf("Enter file name: ");
	scanf(" %s",filename);
    n=write(sockfd,filename,sizeof(filename));

    FILE *fp;
    if(!strcmp(command,"GET")){
        fp=fopen("clientGET.txt","w");
        n=read(sockfd,buffer,1024);
        printf("%s",buffer);
        fprintf(fp,"%s",buffer);
        fclose(fp);

    }
    if(!strcmp(command,"PUT")){
        fp=fopen(filename,"r");
        fgets(buffer,1024,fp);
        printf("%s",buffer);
        n=write(sockfd,buffer,1024);
        fclose(fp);
        
    }
}..