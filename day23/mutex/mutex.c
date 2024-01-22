#include<stdio.h>


pthread_mutex_t my_mutex;
int i;
void *thread_inc1(void *arg){
