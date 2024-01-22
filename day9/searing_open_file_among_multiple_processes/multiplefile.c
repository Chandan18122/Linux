#include<stdio.h>
#include<fcntl.h>

int main(){
	int fd;
	fd=open("dumpdemo.txt",O_RDWR|O_CREAT|O_TRUNC,0660);
	printf("fd = %d\n",fd);
	
	while(1);
	close(fd);
	
	return 0;	
}
