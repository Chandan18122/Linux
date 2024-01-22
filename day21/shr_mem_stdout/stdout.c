#include<stdio.h>
#include<sys/shm.h>
#include<string.h>
#define SIZE 20
int main(){
	char *ptr;
	int shmid,pid,i;
	
	//create shared memory area
	shmid = shmget((key_t)55,20,IPC_CREAT|0666);
	
	/*Attach pointer to shared memory area*/
	ptr = (char*)shmat(shmid,(char*)0,0);  
	
	pid = fork();
	if(pid ==0){
		/*strcpy(ptr,"Shared Memory\n");*/
		//
		i = read(0,ptr,SIZE);
		if(i==-1)
			printf("\nRead failed\n");
		else
			printf("Chaild reads %s\n",ptr);
	}
	else{
		//*write data from stdout*/
		wait(0);
		write(1,ptr,SIZE);
		printf("PARENT reads : %s\n",ptr);
		shmctl(shmid,IPC_RMID,NULL);
	}
}
