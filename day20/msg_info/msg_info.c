#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<sys/msg.h>


main(){
	int qid;
	struct msqid_ds buf;
	
	qid = msgget(55, IPC_CREAT|0664);
	printf("Qid = %d\n",qid);
	msgctl(qid,IPC_STAT,&buf);
	printf("Hear are the details of the queue\n");
	printf("No of msg's in q %ld\n",buf.msg_qnum);
	printf("No of bytes in q %ld\n",buf.msg_cbytes);

}
