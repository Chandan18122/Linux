#include <stdio.h>
void myprint(char *msg){
	if(msg !=NULL)
	printf("messig = %s \n",msg);
}
int main() {
 	char buff[] = "linux";
	myprint(buff);
	return 0;
}
