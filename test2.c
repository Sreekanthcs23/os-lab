#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/shm.h>
#include<stdlib.h>
struct process{
    int id,at,bt,wt,tt;
};
float avgwtsr=0,avgwtlr=0,avgttsr=0,avgttlr=0,avgsr[2],avglr[2];
float* lrtf(struct process p[10],int n)
{
    int temp[10],t=0,count=0,short_P,prev,k=0;
    float avg_wt=0,avg_tt=0,total_wt=0,total_tt=0;
	for(int i=0;i<n;i++)
	{
		temp[i]=p[i].bt;
	}
    p[9].bt=-1;
    printf("GANTT CHART\n");
    for(t=0;count!=n;t++)
    {

        short_P=9;
        for(int i=0;i<n;i++)
        {
            if(p[i].bt>p[short_P].bt && (p[i].at<=t && p[i].bt>0))
            {

                short_P=i;
            }

        }
        if(short_P!=9)
        {
            k=k+1;
        if(k==1)
        {
             printf("%d->p%d->",t,p[short_P].id);
        }
        else if(prev!=short_P && count<n-1)
            {
                 printf("%d->p%d->",t,p[short_P].id);
            }
        else if(prev!=short_P && count==n-1)
        {
            printf("%d->p%d->%d",t,p[short_P].id,t+p[short_P].bt);
        }
        p[short_P].bt=p[short_P].bt-1;


        if(p[short_P].bt==0)
        {
            count++;
            p[short_P].wt=t+1-p[short_P].at-temp[short_P];
            p[short_P].tt=t+1-p[short_P].at;
            total_wt=total_wt+p[short_P].wt;
            total_tt=total_tt+p[short_P].tt;
        }
        prev=short_P;
        }
       


    }
    avg_wt=total_wt/n;
    avg_tt=total_tt/n;
    avglr[0]=total_wt/n;
	avglr[1]=total_tt/n;
    printf("\n");
    printf("Id WT TAT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\n",p[i].id,p[i].wt,p[i].tt);
    }
    printf("Avg waiting time of the process is %f\n",avg_wt);
    printf("Avg turn around time of the process %f\n",avg_tt);
    return (float*)avglr;
}
float* srtf(struct process p[10],int n)
{
	int temp[10],t,count=0,short_P,prev,k=0;
    float avg_wt=0,avg_tt=0,total_wt=0,total_tt=0;
	for(int i=0;i<n;i++)
	{
		temp[i]=p[i].bt;
	}
    p[9].bt=10000;
    printf("GANTT CHART\n");
    for(t=0;count!=n;t++)
    {

        short_P=9;
        for(int i=0;i<n;i++)
        {
            if(p[i].bt<p[short_P].bt && (p[i].at<=t && p[i].bt>0))
            {

                short_P=i;
            }

        }
        if(short_P!=9)
        {
            k=k+1;
        if(k==1)
        {
             printf("%d->p%d->",t,p[short_P].id);
        }
        else if(prev!=short_P && count<n-1)
            {
                 printf("%d->p%d->",t,p[short_P].id);
            }
        else if(prev!=short_P && count==n-1)
        {
            printf("%d->p%d->%d",t,p[short_P].id,t+p[short_P].bt);
        }
        p[short_P].bt=p[short_P].bt-1;


        if(p[short_P].bt==0)
        {
            count++;
            p[short_P].wt=t+1-p[short_P].at-temp[short_P];
            p[short_P].tt=t+1-p[short_P].at;
            total_wt=total_wt+p[short_P].wt;
            total_tt=total_tt+p[short_P].tt;
        }
        prev=short_P;

        }
        

    }
    avg_wt=total_wt/n;
    avg_tt=total_tt/n;
    avgsr[0]=total_wt/n;
	avgsr[1]=total_tt/n;
    printf("\n");
    printf("Id WT TAT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\n",p[i].id,p[i].wt,p[i].tt);
    }
    printf("Avg waiting time of the process is %f\n",avg_wt);
    printf("Avg turn around time of the process %f\n",avg_tt);
    return (float*)avgsr;
}
int main()
{
    int shmid = shmget((key_t)2456,1024,0666|IPC_CREAT);
    void *sharedMemory = shmat(shmid,NULL,0);
    int o=0,e=0;
    float avg_wt=0,avg_tt=0;
    float* avg_t;
    float *avg=(float*)sharedMemory;
    struct process p[10];
	struct process odd[10];
	struct process even[10];
	printf("Process 0 - parent id:%d\n",getpid());
	pid_t pid1 = fork();

	//Inside 1
	if(pid1==0)
	{
		printf("Process 1 - id:%d parent id:%d\n",getpid(),getppid());
		pid_t pid2 = fork();

		//Inside 2
		if(pid2==0)
		{
			printf("Process 2 -id:%d parent id:%d\n",getpid(),getppid());
            exit(0);
		}
        wait(NULL);

		pid_t pid3 = fork();

		//Inside 3
		if(pid3==0)
		{ 
		       
            printf("Process 3 -id:%d parent id:%d\n",getpid(),getppid());
			 printf("Enter burst time and arrival time of each process\n");
             for(int i=0;i<8;i++)
              {
                 printf("p%d\n",i);
                 scanf("%d%d",&p[i].bt,&p[i].at);
                  p[i].id=i;
				 if(i==0 |i%2==0)
				 {
					 even[e++]=p[i];
				 }
				 else
				 {
					 odd[o++]=p[i];
				 }
                

              }
            pid_t pid5 = fork();
			//Inside 5
			if(pid5==0)
			{
				printf("Process 5 -id:%d parent id:%d\n",getpid(),getppid());
				avg_t=lrtf(odd,o);
				*avg=*avg_t;
				avg+=1;
				*avg=*(avg_t+1);
				
			        exit(0);
			}
            wait(NULL);
			pid_t pid6 = fork();

			//Inside 6
			if(pid6==0)
			{
				printf("Process 6 -id:%d parent id:%d\n",getpid(),getppid());
				avg_t=srtf(even,e);
				avg+=2;
				*avg=*avg_t;
				avg+=1;
				*avg=*(avg_t+1);
			        exit(0);
			}
            wait(NULL);
			pid_t pid7 = fork();

			//Inside 7
			if(pid7==0)
			{
				printf("Process 7 -id:%d parent id:%d\n",getpid(),getppid());
				avg_wt=(*avg)-(*(avg+2));
				avg_tt=(*(avg+1))-(*(avg+3));
				if(avg_wt<0)
					printf("Defference between average waiting time in SRTF and LRTF= %f\n",-(avg_wt));
				else
				   printf("Defference between average waiting time in SRTF and LRTF= %f\n",avg_wt);
			
				if(avg_tt<0)
					printf("Defference between average turn around time in SRTF and LRTF= %f\n",-(avg_tt));
				else
				   printf("Defference between average turn around time in SRTF and LRTF= %f\n",avg_tt);
			
			    exit(0);
			}
			wait(NULL);
			exit(0);
		}
        wait(NULL);

		pid_t pid4 = fork();
		//Inside F
		if(pid4==0)
		{
			printf("Process 4 -id:%d parent id:%d\n",getpid(),getppid());
		
			exit(0);
		}

		wait(NULL);
		exit(0);
	}
	
	shmdt(sharedMemory);
	wait(NULL);
	return 0;
}
