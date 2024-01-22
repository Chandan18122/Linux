#include<stdio.h>
#include<stdlib.h>

void buggy(int *p){
	p[0] =10;
	free(p);
}

int main()
{
	int *intptr;
	intptr = (int *)malloc(sizeof(int));
	buggy(intptr);
	free(intptr);
	return 0;
}
