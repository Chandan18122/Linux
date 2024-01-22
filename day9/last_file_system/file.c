#include<stdio.h>
#include<fcntl.h>

int main(){
	int fd1,fd2;

	fd1 = open("linux.txt",O_WRONLY|O_CREAT|O_TRUNC,0777);
	fd2 = fcntl(fd1, F_DUPFD,55);
	
	printf("duplicate value of fd1 is fd2 = %d\n",fd2);
	
	close(fd1);
	close(fd2);
	return 0;
}
