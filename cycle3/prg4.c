#include<stdio.h>

struct process
{
	int btime;
	int artime;
	int wtime;
	int ttime;
	int flag;
};

int main()
{
	int n,time,end,count=0,small;
	struct process p[10];
	printf("Enter number of proceses: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		p[i].flag=0;
	printf("Enter details:\n");
	for(int i=0;i<n;i++) 
	{
		printf("p%d bursttime:",i);
		scanf("%d",&(p[i].btime));
		printf("p%d arrival time:",i);
		scanf("%d",&(p[i].artime));
	}
	
	p[9].btime = 10000;
	time = 0;
	
	while(count<n)
	{
		
		small = 9;
		for(int i=0;i<n;i++)
		{
			if((p[i].artime <= time) && (p[i].btime < p[small].btime) && (p[i].flag==0))
			{
				small = i;
			}
		}
		printf("t:%d\n",time);
		time = time+p[small].btime;
		p[small].wtime = time - p[small].btime - p[small].artime;
		p[small].ttime = p[small].wtime + p[small].btime;
		count++;
		p[small].flag=1;
	}
	
	for(int i=0;i<n;i++)
	{
		printf("p%d \twtime:%d \tttime:%d\n",i,p[i].wtime,p[i].ttime);
	}
	
	return 0;
}

















