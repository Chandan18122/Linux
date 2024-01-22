#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

main(){
	int qid;
	qid = msgget(555,IPC_CREAT|0640);
	printf(" Qid = %d\n",qid);
	getchar();
	msgctl(qid,IPC_RMID,NULL);
}
