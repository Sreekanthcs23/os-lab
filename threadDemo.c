#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int var = 1;

void *fun1(void *ptr)
{
	while(1)
	{
		printf("t1:%d\n",var++);
		sleep(1);
	}
	return NULL;	
}

void *fun2(void *ptr)
{
	while(1)
	{
		printf("t2:%d\n",var--);
		sleep(1);
	}
	return NULL;	
}

int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,fun1,NULL);
	pthread_create(&t2,NULL,fun2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
