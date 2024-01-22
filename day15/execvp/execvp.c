#include<stdio.h>
int main(){
	char *args[3];
	printf("I am going to exec an ls process in current process\n");
	
	args[0] = "ls";
	args[1]= "-l";
	args[2]=0;
	execvp("ls",args);
	printf("I execed 'ls' process\n");
}
