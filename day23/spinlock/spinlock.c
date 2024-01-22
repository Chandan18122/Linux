#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<error.h>
#include<bits/types.h>
#include<sys/types.h>

static pthread_spinlock_t slock;

void *spinlockThread(void *i){
	int rc;
	int count = 0;
	
	printf("Entered thread %d, getting Spain lock \n",(int *)i);
	rc = pthread_spin_lock(&slock);
	printf("%d Thread unlock the spin lock...agter 5 second\n",(int *)i);
	rc = pthread_spin_unlock(&slock);
	
	printf("%d thread complete\n",(int *)i);
	return NULL;
}

int main(){
	int rc =0;
	pthread_t thread,thread1;
	if(pthread_spin_init(&slock,PTHREAD_PROCESS_PRIVATE)!=0)
		printf("init");
	printf("Main, get spin lock\n");
	rc = pthread_spin_lock(&slock);
	
	printf("Main, create the spin lock thread\n");
	rc = pthread_create(&thread,NULL,spinlockThread, (int *)1);
	
	printf("Main,wait a bit holding the spin lock\n");
	sleep(5);

	printf("Main, now unlock the spin lock\n");
	rc = pthread_spin_unlock(&slock);
	if(rc == 0)
		printf("\n Main Thread Successfully unlocked\n");
	else
		printf("\n Main Thread Unseccessfully unlocked\n");

	printf("main, wait for the thread to end\n");
	rc = pthread_join(thread, NULL);
	rc = pthread_spin_destroy(&slock);
	printf("Main compleated\n");
	return 0;
}
