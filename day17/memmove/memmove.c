#include<stdio.h>
#include<string.h>

int main(){

	char dest[] = "oldstring";
	const char src[] = "newstring";
	
	printf("Before memove dest = %s, src = %s\n", dest, src);
	
	memmove(dest, src, 9);
	
	printf("After memove dest = %s, src = %s\n", dest, src);

}
