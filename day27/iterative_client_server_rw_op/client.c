#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdlib.h>

#define PORT 8000
#define SERVER_IP "127.0.0.1"
#define MAXSZ 100

main(){
	int sockfd; //to create socket
	char buf[200];
	int n;
	char msg1[MAXSZ];
	char msg2[MAXSZ];
	struct sockaddr_in serverAddres; //client will connect on this
	
	//create socket
	sockfd = socket(AF_INET, SOCK_STREAM,0);
	//initialize the socket addresses
	memset(&serverAddres,0, sizeof(serverAddres));
	serverAddres.sin_family = AF_INET;
	serverAddres.sin_addr.s_addr = inet_addr(SERVER_IP);
	serverAddres.sin_port = htons(PORT);

	//client connect to sever on port
	connect(sockfd, (struct sockaddr *) &serverAddres, sizeof(serverAddres));
	//send to server and recive from server

	while(1){

		printf("Enter the data that you want to send to the server\n");
		fgets(msg1,MAXSZ,stdin);
		if(msg1[0] == '#') break;
		
		n = strlen(msg1)+1;
		send(sockfd,msg1,n,0);
		
		n = recv(sockfd,msg1,MAXSZ,0);
		printf("rec'd message from server : %s\n",msg1);
	}
	
	close(sockfd);
}
