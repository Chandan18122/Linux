#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>

int main(){
	int fd,i;
	char *c;
	struct stat file_info;
	fd = open("kernal.txt", O_CREAT|O_RDWR,0777);
	
	write(fd, "linux kernal Technology",25);
	fstat(fd,&file_info);
	printf("File size is %ld\n",file_info.st_size);

	c = mmap(0, file_info.st_size, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);

	perror("mmap");
	for(i=0;i<=16;i++)
	printf("%s\n",c);
	
	munmap(c, file_info.st_size);
	close(fd);
	return 0;
}
