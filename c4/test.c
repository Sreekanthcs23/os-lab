/* Roll No: B20CSB65
   Name: Sreekanth cs
   Name of the Experiment: Producer consumer problem */

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include<stdlib.h>

int empty,full,mutex;
int in=0,out=0;
int buffer[5];

void w(int *s)
{
	while(*s <= 0);
	*s = *s - 1;
}

void s(int *s)
{
	*s = *s+1;
}

void *producer(void *ptr)
{
	int item;
	for(int i=0;i<15;i++)
	{
		item = rand();
		w(&empty);
		w(&mutex);
		sleep(1);
		buffer[in] = item;
		printf("Producer produced item %d in position %d\n",item,in);
		in = (in+1)%5;
		s(&mutex);
		s(&full);
		sleep(1);
	}
}

void *consumer(void *ptr)
{
	for(int i=0;i<15;i++)
	{
		w(&full);
		w(&mutex);
		sleep(1);
		int item = buffer[out];
		printf("Consumer consumed item %d in position %d\n",item,out);
		out = (out+1)%5;
		s(&mutex);
		s(&empty);
		sleep(1);
	}
}

int main()
{
	pthread_t p,c;
	mutex=1;
	empty=5;
	full=0;
	
	pthread_create(&p,NULL,(void *)producer,NULL);
	pthread_create(&c,NULL,(void *)consumer,NULL);
	
	pthread_join(p,NULL);
	pthread_join(c,NULL);
	
	return 0;
}

























 
