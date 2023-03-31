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
	printf("Process A - parent id:%d  process id:%d\n",getppid(),getpid());
	pid_t pid1 = fork();
	
	//Inside B
	if(pid1==0)
	{
		printf("Process B - parent id:%d  process id:%d\n",getppid(),getpid());
		pid_t pid3 = fork();
		
		//Inside D
		if(pid3==0)
		{
			printf("Process D - parent id:%d  process id:%d\n",getppid(),getpid());
			pid_t pid4 = fork();
			
			//Inside H
			if(pid4==0)
			{
				printf("Process H - parent id:%d  process id:%d\n",getppid(),getpid());
				pid_t pid5 = fork();
				//Inside I
				if(pid5==0)
				{
					printf("Process I - parent id:%d  process id:%d\n",getppid(),getpid());
					sleep(20);
					exit(0);
				}
					
				wait(NULL);
				exit(0);
			} 
			wait(NULL);
			exit(0);
		}
		
		pid_t pid6 = fork();
		
		//Inside E
		if(pid6==0)
		{
			printf("Process E - parent id:%d  process id:%d\n",getppid(),getpid());
			sleep(20);
			exit(0);
		}
			
		pid_t pid7 = fork();
		//Inside F
		if(pid7==0)
		{
			printf("Process F - parent id:%d  process id:%d\n",getppid(),getpid());
			sleep(20);
			exit(0);
		}
			
		wait(NULL);
		exit(0);	
	}
	
	//Process A
	pid_t pid2 = fork();
	
	//Inside C
	if(pid2==0)
	{
		printf("Process C - parent id:%d  process id:%d\n",getppid(),getpid());
		pid_t pid8 = fork();
		
		//Inside G
		if(pid8==0)
		{
			printf("Process G - parent id:%d  process id:%d\n",getppid(),getpid());
			sleep(20);
			exit(0);
		}
			
		wait(NULL);
		exit(0);
	}
	wait(NULL);
	return 0;
}


















