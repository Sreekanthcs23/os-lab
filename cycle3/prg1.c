#include<stdio.h>

struct process
{
	int btime;
	int wtime;
	int ttime;
};

int main() 
{
	int n;
	struct process p[10];
	printf("Enter number of proceses: ");
	scanf("%d",&n);
	printf("Enter burst time:\n");
	for(int i=0;i<n;i++) 
	{
		printf("p%d:",i);
		scanf("%d",&(p[i].btime));
	}
	p[0].wtime = 0;
	for(int i=1;i<n;i++)
	{
		p[i].wtime = p[i-1].wtime + p[i-1].btime;
	}
	
	for(int i=0;i<n;i++)
	{
		p[i].ttime = p[i].wtime+p[i].btime;
	}
	
	for(int i=0;i<n;i++)
	{
		printf("p%d \twtime:%d \tttime:%d\n",i,p[i].wtime,p[i].ttime);
	}
	return 0;
}



















