#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd,len;
	char write_buf[50]="hi, how are you1?, wow?";
	char read_buf[50];
	
	fd = open("linux_kernal.txt",O_CREAT|O_RDWR, 777);
	len = write(fd,write_buf,50);
	printf("return value from write optn = %d\n",len);
	
	lseek(fd,0,SEEK_SET);
	read(fd,read_buf,300);
	
	printf("data from buffer = %s\n",read_buf);
	close(fd);
	return 0;
}
