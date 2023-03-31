/* Roll No: B20CSB65
   Name: Sreekanth cs
   Name of the Experiment: System call fork */

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main() 
{
	pid_t pid1 = fork();
	int c=0;
	if(pid1==0)
	{
		sleep(5);
		printf("Child 1 finishes\n");
		exit(0);
	}
	
	pid_t pid2 = fork();
	
	if(pid2==0)
	{
		sleep(3);
		printf("Child 2 finishes\n");
		exit(0);
	}
	
	pid_t pid3 = fork();
	
	if(pid3==0)
	{
		
		printf("Child 3 finishes\n");	
		exit(0);
	}
	sleep(7);
	printf("Parent finishes\n");
}
