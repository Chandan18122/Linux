#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main(){
	int ret, i, cnt = 0;
	errno = 0;
	ret = nice(1);
	if(ret == -1 && errno != 0)
		perror("nice");
	else
		printf("nice valude is now %d\n",ret);
	while(1){
		printf("Process with nice valude %d count = %d\n",ret,cnt);
		for(i = 0;i<1000; i++);
		cnt++;
	}
}	
