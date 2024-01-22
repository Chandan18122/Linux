#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void myinit(){
	printf("\nI am in INIT FUNCTION\n");
}
void *mythread(void *i){
	printf("\nIam in mythread : %d\n",(int *)i);
	pthread_once(&once, myinit);
	//sleep(10);
	printf("\nExit from mythread : %d\n",(int *)i);
}

int main(){

	pthread_t thread1,thread2,thread3;
	int err;
	void *tret;
	pthread_create(&thread1,NULL, mythread,(int *)1);
	//sleep(2);
	pthread_create(&thread2,NULL, mythread,(int *)2);
	//sleep(2);
	pthread_create(&thread3,NULL, mythread,(int *)3);
	
	
	pthread_exit(NULL);

}
