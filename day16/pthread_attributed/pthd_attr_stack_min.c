#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<bits/local_lim.h>

void* Proc(void* param){
	sleep(2);
	return 0;
}

int main(){
	pthread_attr_t	Attr;
	pthread_t	id;
	int		ret;
	void		*stackbase;
	size_t		size1;
	int 	size = PTHREAD_STACK_MIN + PTHREAD_STACK_MIN;
	stackbase = (void *) malloc(size);
	void* my_stack;
	ret = pthread_attr_init(&Attr);
	ret = pthread_attr_getstacksize(&Attr, &size);
	printf("Default Stack Size = %lu\n", size1);
	printf("Thread Minimum Stack Size = %lu\n", PTHREAD_STACK_MIN);
	
	ret = pthread_attr_getstacksize(&Attr, &size);
	ret = pthread_attr_getstacksize(&Attr, &size1);
	printf("\nUser Stack Size = %lu\n",size1);
	
	return 0;

}
