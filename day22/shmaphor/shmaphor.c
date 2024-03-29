#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int get_semaphore(void);
int release_semaphore(void);
int sem_id;

struct sembuf sem_op;

int main(){
	int i;
	sem_id = semget((key_t)1234,1,0666|IPC_CREAT);
	
	if(semctl(sem_id,0,SETVAL,1)<0)
		printf("error\n");
	for(i=0;i<=5;i++){
		get_semaphore();
		printf("%d:got the semaphore\n",getpid());
		sleep(1);
		printf("%d: release the semaphore\n",getpid());
		release_semaphore();
		sleep(1);
	}
	if(semctl(sem_id,0,SETVAL,1)<0)
		printf("failed to delete the semaphore\n");
	else
		printf("semaphore deleted\n");
		
		
}
int get_semaphore(void){
	sem_op.sem_num=0;
	sem_op.sem_op=-1;
	sem_op.sem_flg=0;
	
	if(semop(sem_id,&sem_op,1)<0){
		printf("failed to get the semaphore\n");
		return -1;
	}
	return 0;
}
int release_semaphore(void){
	sem_op.sem_num=0;
	sem_op.sem_op=1;
	sem_op.sem_flg=0;
	
	if(semop(sem_id,&sem_op,1)<0){
		printf("failed to get the semaphore\n");
		return -1;
	}
	return 0;
}

