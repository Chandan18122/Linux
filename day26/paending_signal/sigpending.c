#include<stdio.h>
#include<signal.h>

void check_pending_sigs(sigset_t s){
	int i,res;
	for(i=1;i<5;i++){
		res = sigismember(&s,i);
		if(res)
			printf("Signal %d is pending\n",i);
		else
			printf("Signal %d is not pending\n",i);
	}
}

void sighand(int no){
	printf("I am in sighandler\n");
}

int main(){
	sigset_t s_set,s;
	signal(1,sighand);

	sigemptyset(&s_set);
	sigaddset(&s_set,2);
	
	sigprocmask(SIG_BLOCK|SIG_SETMASK,&s_set, NULL);
	printf("PID of the process = %d\n",getpid());
	printf("Send me signal one and see hte effect now ");
	
	getchar();
	getchar();
	sigpending(&s);
	check_pending_sigs(s);
	
	getchar();
	sigprocmask(SIG_UNBLOCK,&s_set,NULL);
	printf("Now signals are unblocked\n");
	
	while(1);
}

