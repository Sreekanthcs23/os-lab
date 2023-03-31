#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/shm.h>
#include<stdlib.h>

int main()
{
    int shmid = shmget((key_t)2456,1024,0666|IPC_CREAT);
    void *sharedMemory = shmat(shmid,NULL,0);
    int n,mark[10],id[10];
    int *avg=(int *)sharedMemory;
    
	printf("Enter the number of students\n");
	scanf("%d",&n);
	printf("Process 0 - parent id:%d\n",getpid());
	pid_t pid1 = fork();
	if(pid1==0)
		{
			printf("Process 1 -id:%d parent id:%d\n",getpid(),getppid());
			printf("Enter the mark of each student\n");
		    for(int i=0;i<n;i++)
            {
                printf("student:%d\n",i+1);
                scanf("%d",&mark[i]);
                *avg=mark[i];
                avg+=1;
            }
			exit(0);
		}
        wait(NULL);
    pid_t pid2 = fork();
		//Inside F
		if(pid2==0)
		{
			printf("Process 2 -id:%d parent id:%d\n",getpid(),getppid());
            for(int i=0;i<n;i++)
            id[i]=i+1;
            for(int i=0;i<n;i++)
            {
                mark[i]=*avg;
                avg+=1;
            }
            for(int i=0;i<n;i++)
            {
               printf("mark:%d=%d",i+1,mark[i]);
            }
			exit(0);
		}
        wait(NULL);

	shmdt(sharedMemory);
	wait(NULL);
	return 0;
}
