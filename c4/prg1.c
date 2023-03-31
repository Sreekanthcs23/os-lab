#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include<stdlib.h>

sem_t empty,full,mutex;
int in=0,out=0;
int buffer[5];

void *producer(void *ptr)
{
	int item;
	for(int i=0;i<15;i++)
	{
		item = rand();
		sem_wait(&empty);
		sem_wait(&mutex);
		buffer[in] = item;
		printf("Producer produced item %d in position %d\n",item,in);
		in = (in+1)%5;
		sem_post(&mutex);
		sem_post(&full);
		sleep(1);
	}
}

void *consumer(void *ptr)
{
	for(int i=0;i<15;i++)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		int item = buffer[out];
		printf("Consumer consumed item %d in position %d\n",item,out);
		out = (out+1)%5;
		sem_post(&mutex);
		sem_post(&empty);
		sleep(1);
	}
}

int main()
{
	pthread_t p,c;
	sem_init(&mutex,0,1);
	sem_init(&empty,0,5);
	sem_init(&full,0,0);
	
	pthread_create(&p,NULL,(void *)producer,NULL);
	pthread_create(&c,NULL,(void *)consumer,NULL);
	
	pthread_join(p,NULL);
	pthread_join(c,NULL);
	
	return 0;
}

























 
