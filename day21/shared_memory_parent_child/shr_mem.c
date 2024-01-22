#include<stdio.h>
#include<sys/shm.h>
#include<string.h>

int main(){
	char *ptr;
	int shmid,pid;
	
	//create shared memory area
	shmid = shmget((key_t)1,20,IPC_CREAT|0666);
	
	/*Attach pointer to shared memory area*/
	ptr = (char*)shmat(shmid,(char*)0,0);  //2nd arg is addr arg i.e 0, leaving to kernal to attach at free
						//addr space in the process
						// SHM_RDONLY
	
	pid = fork();
	if(pid ==0){
		//*copy data in the child process */
		strcpy(ptr,"Shared Memory\n");
	}
	else{
		wait(0);
		//*Read data from parent*/
		printf("PARENT reads ... = %c\n",*(ptr+2));
		printf("PARENT reads : %s\n",ptr);
	}
}
