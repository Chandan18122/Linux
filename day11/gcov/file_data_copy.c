#include<stdio.h>
#include<fcntl.h>
#define BUF_SIZE 1024

int main(){
	int inputFd,outputFd, openFlags;
	mode_t filePerms;
	ssize_t numRead;
	char buf[BUF_SIZE];
	
	inputFd = open("fileA.txt",O_RDWR,777);
	if(inputFd == -1){
		printf("Open Error\n");
		return;
	}
	
	outputFd = open("fileB.txt",O_RDWR,777);
	if(outputFd == -1){
		printf("Opening file\n");
		return;
	}
	while((numRead = read(inputFd , buf,BUF_SIZE)) >0){
		if(write(outputFd,buf,numRead) != numRead){
			printf("write Error\n");
		}
		printf("%d\n",numRead);
	}
	if(numRead == -1){
		printf("Read Error\n");
		return;
	}
	if(close(inputFd) == -1){
		printf("close input\n");
		return;
	}
	if(close(outputFd) == -1){
		printf("close output\n");
		return;
	}
	return 0;
}
