#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pid, stat;
	pid = fork();
	if(pid == 0){
		printf("child pid %d\n",pid);
		printf("CHILD PROCESS\n");
		exit(0);
	}
	printf("befor wait parent pid %d\n",pid);
	pid = wait(&stat);
	printf("wait pid : %d\n",WEXITSTATUS(stat));
	printf("after wait parent pid : %d\n",pid);
}
