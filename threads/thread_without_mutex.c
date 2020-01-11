#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 5


/*
   create 5 threads, each thread add 1M on the global varaible sum
   first time, do this without mutex, each thread can change 'sum' variable
   in the same time .   
*/

int sum = 0 ;
void* run(void* args)
{
	for(int i = 0;i<10000000;i++)
	{
		sum++;
	}
	return NULL;
}
int main()
{

    /* array hold 5 ides for five threads */
	pthread_t thread_id[NUM_THREADS];
	
	
	/* create five threads */
	for(int i = 0;i<NUM_THREADS;i++)
	{
		pthread_create(&thread_id[i],NULL,run,NULL);
	}
	
	/* join work as wait call system */
	for(int i = 0;i<NUM_THREADS;i++)
	{
		pthread_join(thread_id[i],NULL);
	}
	
	
	printf("Sum = %d\n",sum);	
}
/*

expected output : 5000,000
output: 4895,248
*/




