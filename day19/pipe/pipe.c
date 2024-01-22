#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main() {

	int p[2];
	pipe(p);
	printf("Read end of pipe = %d\t Write end of pipe = %d\n",p[0],p[1]);
	if (fork()){
		char s[20];
		printf("In Parent Enter Data ...\n");
		scanf("%s",s);
		write(p[1],s,strlen(s)+1);
	}
	else{
		char buf[20];
		printf("In Chile Enter Data ...\n");
		read(p[0], buf, sizeof(buf));
		printf("Child pro printing..Data. if the parent process.. %s\n",buf);
	}
	return 0;
}
