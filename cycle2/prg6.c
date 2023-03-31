/* Roll No: B20CSB65
   Name: Sreekanth cs
   Name of the Experiment: Shared memory */

#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

struct student 
{
	char name[10];
	int marks;
};

int increment = sizeof(struct student);

int main()
{
	int shmid = shmget((key_t)2456,1024,0666);
	void *sharedMemory = shmat(shmid,NULL,0);
	
	struct student s[4];
	
	struct student *currentLoc = (struct student*)sharedMemory;
	
	//store info in array
	for(int i=1;i<=4;i++)
	{
		s[i-1] = *(currentLoc);
		currentLoc += increment;
	}
	
	//sort the array
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4-i-1;j++)
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
	for(int i=0;i<4;i++)
	{
		printf("Rank:%d  Name:%s  Marks:%d\n",i+1,s[i].name,s[i].marks);
	}
	
	shmdt(sharedMemory);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
