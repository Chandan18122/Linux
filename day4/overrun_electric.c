#include<stdio.h>
#include<stdlib.h>

void buggy(){
	int *intptr;
	int i;
	intptr = (int *)malloc(sizeof(int)*4);//int data type = 4 bytes
	for(i=0;i<10;i++){
		*intptr = 100;
		printf("Value at ptr intptr = %d\n",(*intptr));
		intptr++;
	}
}
int main()
{
	buggy();
	return 0;
}
