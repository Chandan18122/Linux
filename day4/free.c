#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *intptr;
	intptr = (int *)malloc(sizeof(int));
	*intptr = 100;
	printf("Value at ptr intptr = %d\n",(*intptr));
	free(intptr);
	*intptr = 50;
	printf("Value at ptr intptr = %d\n",(*intptr));
	return 0;
}
