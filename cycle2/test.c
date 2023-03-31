/* Roll No: B20CSB65
   Name: Sreekanth cs
   Name of the Experiment: Shared Memory */

#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

struct student 
{
	char name[10];
	int marks;
}s;

int increment = sizeof(struct student);

int main()
{
	int n;
	printf("Enter number of students:");
	scanf("%d",&n);
	
	pid_t pid = fork();
	
	if(pid==0)
	{
		
		
		int shmid = shmget((key_t)2456,1024,0666|IPC_CREAT);
		void *sharedMemory = shmat(shmid,NULL,0);
		
		struct student *currentLoc = (struct student *)sharedMemory;
		for(int i=1;i<=n;i++)
		{
			printf("Enter the name:");
			scanf("%s",s.name);
			printf("Enter the marks:");
			scanf("%d",&(s.marks));
			*currentLoc = s;
			currentLoc += increment;
		}
		
		shmdt(sharedMemory);
		exit(0);
	}
	
	wait(NULL);
	
	int shmid = shmget((key_t)2456,1024,0666);
	void *sharedMemory = shmat(shmid,NULL,0);
	
	struct student s[n];
	
	struct student *currentLoc = (struct student*)sharedMemory;
	
	//store info in array
	for(int i=1;i<=n;i++)
	{
		s[i-1] = *(currentLoc);
		currentLoc += increment;
	}
	
	//sort the array
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(s[j].marks < s[j+1].marks)
			{
				struct student temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}
	}
		
	//print rank detalis
	for(int i=0;i<n;i++)
	{
		printf("Rank:%d  Name:%s  Marks:%d\n",i+1,s[i].name,s[i].marks);
	}
	
	shmdt(sharedMemory);
	shmctl(shmid,IPC_RMID,NULL);
	
	return 0;
}
