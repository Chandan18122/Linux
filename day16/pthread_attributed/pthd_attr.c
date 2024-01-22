#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/mman.h>

void* Proc(void* param){
	sleep(2);
	return 0;
}

int main(){
	pthread_attr_t	Attr;
	pthread_t	id;
	void		*Stk;
	size_t		Size;
	int 		err;

	size_t my_stksize = 3000000;
	void* my_stack;
	pthread_attr_init(&Attr);
	pthread_attr_getstacksize(&Attr, &Size);
	pthread_attr_getstackaddr(&Attr, &Stk);

	printf("Default Addr = %08x \t default size = %d\n", Stk,Size);

	my_stack=(void *) malloc(my_stksize);
	pthread_attr_setstack(&Attr,my_stack,my_stksize);
	pthread_create(&id,&Attr,Proc,NULL);
	pthread_attr_getstack(&Attr,&Stk,&Size);
	printf("New defined stack : add = %08x and size =%d\n",Stk,Size);
	sleep(3);
	return 0;

}
