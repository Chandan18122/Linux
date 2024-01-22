#include<stdio.h>
#include<unistd.h>
int main(){
	printf("current process\n");
	fork();
	fork();
	fork();
	printf("LINUX process\n");
	while(1);
	return 0;
}
