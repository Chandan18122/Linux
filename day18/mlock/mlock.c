#include<stdio.h>
#include<unistd.h>

int main() {

	size_t i;
	const int alloc_size = 1024 * 1024;
	char* memory = malloc(alloc_size);
	mlock(memory, alloc_size);

	for(i = 0;i<alloc_size; i++)
	
		memory[i] = '#';

	printf("allocated memory initializedn with = %s\n",memory);
	munlock(memory, alloc_size);

}

