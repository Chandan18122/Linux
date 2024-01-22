#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdlib.h>

#define PORT 8000
#define MAXSZ 100

int main(){
	int sockfd;
	int newsockfd;
	int listfd,connfd,retval;
	
	socklen_t clilen;
	struct sockaddr_in clientAddres, serverAddres;
	int n;
	char msg[MAXSZ];
	int clientAddressLength;

	listfd = socket(AF_INET, SOCK_STREAM,0);
	if(listfd <0){
		perror("Sock");
		exit(1);
	}
	
	bzero(&serverAddres, sizeof(serverAddres));
	serverAddres.sin_family = AF_INET;
	serverAddres.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddres.sin_port = htons(8000);
	
	retval = bind(listfd, (struct sockAddres *) &serverAddres, sizeof(serverAddres));
	if(retval < 0){
		perror("bind:");
		exit(2);
	}
	listen(listfd, 5);
	
	while(1){
		printf("\n*****Server wating for new client connection:*****\n");
		clientAddressLength = sizeof(clientAddres);
		newsockfd = accept(listfd, (struct sockaddr*)&clientAddres, &clientAddressLength);
		
		while(1){
			n=recv(newsockfd,msg,MAXSZ,0);
			if(n==0){
				close(newsockfd);
				break;
			}
			msg[n]=0;
			send(newsockfd,msg,n,0);
			printf("Receiv dan set : %s\n",msg);
		}
	}
	close(listfd);
}
