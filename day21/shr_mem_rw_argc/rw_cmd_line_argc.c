#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){
	key_t key;
	int shmid;
	char *data;
	int mode;
	if (argc > 2){
		fprintf(stderr,"usage: shmdemo [data_to)write]\n");
		exit(1);
	}
	
	if((shmid = shmget(111, SHM_SIZE, IPC_CREAT|0644))==-1){
		perror("shmget");
		exit(1);
	}
	data = shmat(shmid,(void *)0,0);
	if(data == (char *)(-1)){
		perror("shmget");
		exit(1);
	}

	if (argc == 2){
		printf("writing to segment: \"%s\"\n", argv[1]);
		strncpy(data, argv[1],SHM_SIZE);
	}
	printf("segment contains :  \"%s\"\n", data);
	
	if(shmdt(data) ==-1){
		perror("shmget");
		exit(1);
	}
	return 0;
}
