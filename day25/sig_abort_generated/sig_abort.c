#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

void sighand(int sig_num){
	printf("abort signal rec'd\n");
	printf("We can use this to perform clean up op's\n");
}

int main(){
	signal(SIGABRT, sighand);
	printf("Some things has gone worng\n");
	abort();

	printf("can you see this \n");
	printf("can you see this \n");
	printf("can you see this \n");

}
