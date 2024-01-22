#include<stdio.h>
#include<unistd.h>

int main(){
	long int page_size = sysconf(_SC_PAGESIZE);
	
	printf("My page size : %ld\n",page_size);
	
	void* c1 = sbrk(0);
	printf("program breack address: %p\n", c1);
	printf("sizeof char : %lu\n",sizeof(char));
	
	c1 = ((char*) c1+1);
	printf("C1 : %p\n", c1);
	
	brk(c1);

	void* c2 = sbrk(0);
	printf("program breack address: %p\n", c2);

}
