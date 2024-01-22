


int i=0;
void *myfun(void *null){
	i++;
	int result =0;
	result = result + i*1000;
	printf("result = %d\n",result);
	sleep(1);
	printf("JOB DONE\n");
	
}

int main(){
	pthread_t thread[NUM_THREADS];

	int rc,t,status,deatch_state;

	pthread_attr_getdeatchstate(&attr,&detach_state);
	printf("/n Deatach State : %d\n",(int*)detach_state);

	pthread_attr_init(&addr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED):
	
	for(t = 0; t<NUM_THREAD;t++){
		printf("Creating thread %d\n",t);
		rc = pthread_create(&thread[t],&attr,myfun,NULL);
		if(rc){
			printf("ERROR: return cod form pthread_create() is %d\n",rc);
			exit(-1);
		}
	}
	
	pthread_attr_getdeatchstate(&attr,&deatch_state);
	printf("\nDeatch State : %d\n",(int *)detach_state);

	pthread_attr_destroy(&attr);
	
	printf("\nExiting from main Thread\n");
	
	for(t = 0; t<NUM_THREAD;t++)
	rc = pthread_join(&thread[t],NULL);
	
	return 0;

}
	
