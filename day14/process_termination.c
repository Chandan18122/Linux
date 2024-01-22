#include<stdio.h>

int main() {
	int id;
	int cnt =0;
	printf("I am going to create a new process\n");
	id = fork();
	if(id){
		while(cnt < 10){
			cnt++;
			printf("I ma parent, my child process is : %d\n",id);
			sleep(1);
		}
	}
	else{
		while(cnt <20){
			cnt++;
			printf("I am chule process I got id valuds as : %d\n",id);
			sleep(1);
		}
	}
}
