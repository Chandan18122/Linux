#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void *PrintHello(void *threadid){
	printf("\nHello World!\n");
	printf("I am waitiong\n");
	while(1);
}

int main(){

	pthread_t thread;
	int rc, t =0;
	printf("Creating thread %d\n",t);
	rc = pthread_create(&thread,NULL,PrintHello,NULL);
	printf("\nThread ID : %lu",thread);
	//pthread_join(thread,NULL);
	sleep(6);
	t = pthread_cancel(thread);
	if(t==0)
	printf("\ncancled thread\n");
	printf("\nThread ID : %lu\n",thread);

}
