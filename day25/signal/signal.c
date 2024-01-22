#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void ouch(int sig){
	printf("OUCH! - Igot a signal %d\n",sig);
	//(void) signal(sig, SIG_DFL);
}

int main(){
	
	(void)signal(SIGINT, ouch);
	printf("PID of the proces = %d\n",getpid());
	while(1){
		printf("Hello world\n");
		sleep(1);
	}
}
