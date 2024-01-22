#include<stdio.h>
#include<fcntl.h>

int main(){
	int fd1, fd2, fd3;
	
	fd2 = open("fileopen.txt", O_WRONLY, 777);

	printf("Fd return by kernal for fileopen.txt = %d\n",fd2);
	fd3 = open("fileopen.txt", O_WRONLY, 777);

	printf("Fd return by kernal for fileopen.txt = %d\n",fd3);
	close(fd2);
}
