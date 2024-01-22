#include<stdio.h>
#include<stdlib.h>


int main(int argc,char *argv[]) //argc counts total number of arguments
{				//argv stored all parameters
	int i;
	printf("\nFile Name : %s\n",argv[0]);
	printf("\nTotal Numbers of Argument : %d\n",argc);
	printf("\nArgument Passed : \n");
	for(i =1;i<argc;i++)
	printf("%s ",argv[i]);
	printf("\n");
}
