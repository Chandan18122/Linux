#include<stdio.h>
//forcing to checking the header file in the same directery
#include"file.h"
int main(){
	int a = 10,b=5;
	printf("Addition of a and = %d\n",add(a,b));
	printf("Subtraction of and b = %d\n",sub(a,b));
	return 0;
}
