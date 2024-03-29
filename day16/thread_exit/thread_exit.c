#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void *thr_fn1(void *arg){
	printf("thread 1 returning\n");
	printf("THD ID = %lu\n",pthread_self());
	//sleep(10);
	return ((void*)1);
	//exit(1);
}

void *thr_fn2(void *arg){
	printf("thread 2 exiting\n");
	printf("THD ID = %lu\n",pthread_self());
	//sleep(10);
	pthread_exit((void*)2);
}

int main(void){

	pthread_t tid1,tid2;
	int err;
	void *tret;
	pthread_create(&tid1,NULL, thr_fn1,NULL);
	pthread_create(&tid2,NULL,thr_fn2,NULL);
	pthread_join(tid1,&tret);
	printf("Thread 1 exit code %d\n",(int)tret);
	
	pthread_join(tid2,&tret);
	//sleep(6);
	
	printf("\nThread 2 exit code : %d\n",(int)tret);
	exit(0);

}
