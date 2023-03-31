#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

struct student 
{
	char name[10];
	int marks;
}s;

int increment = sizeof(struct student);

int main()
{
	int n;
	
	int shmid = shmget((key_t)2456,1024,0666|IPC_CREAT);
	void *sharedMemory = shmat(shmid,NULL,0);
	
	printf("Enter number of students:");
	scanf("%d",&n);
	
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
	return 0;
}
