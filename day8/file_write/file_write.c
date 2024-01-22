#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd,len,x;
	char write_buf[60]="Linux ketnal new program ?, wow?";
	fd = open("write_file.txt",O_CREAT | O_RDWR, 777);
	write(fd,write_buf,60);
	
	close(fd);
	return 0;
}
