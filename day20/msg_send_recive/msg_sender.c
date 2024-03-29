#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/msg.h>

struct msgbuf{
	long mtype;
	char data[512];
};

int main(int argc, char *argv[]){
	struct msgbuf v;
	int id;
	
	id = msgget(55, IPC_CREAT|0644);

	printf("id = %d\n",id);
	v.mtype = atoi(argv[1]);
	strcpy(v.data, argv[2]);
	msgsnd(id, &v, strlen(v.data)+1, IPC_NOWAIT); //Flage = 0 or IPC_NOWAIT
	
	return 0;
}
