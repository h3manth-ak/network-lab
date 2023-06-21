#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>


void main(int argc,char * argv[]){
    int portno,serv_sockfd,newsockfd,n,clilen;
    struct sockaddr_in serv_addr,client_addr;
    char command[50]={0},filename[20]={0},buffer[1024]={0};
    portno=atoi(argv[1]);
    serv_sockfd=socket(AF_INET,SOCK_STREAM,0);

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(portno);
    serv_addr.sin_addr.s_addr=INADDR_ANY;

    n=bind(serv_sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    if(n < 0)
		printf("Error-aah");
    
    listen(serv_sockfd,5);
    newsockfd=accept(serv_sockfd,(struct sockaddr *)&client_addr,&clilen);
    clilen=sizeof(client_addr);
    n=read(newsockfd,command,sizeof(command));
    if(n < 0)
		printf("Errovvv");
    
    printf("command : %s\n",command);
    n=read(newsockfd,filename,sizeof(filename));
    if(n < 0)
		printf("Error-gcvghc");
    
    printf("filename : %s\n",filename);

    FILE *fp;
    if (!strcmp(command,"GET")){
        fp=fopen(filename,"r");
        fgets(buffer,sizeof(buffer),fp);
        printf("%s\n",buffer);
        n=write(newsockfd,buffer,1023);
        fclose(fp);

    }
    if(!strcmp(command,"PUT")){
        fp=fopen("newfile.txt","w");
        n=read(newsockfd,buffer,sizeof(buffer));
        printf("%s",buffer);
        fprintf(fp,"%s",buffer);
        fclose(fp);
    }

}