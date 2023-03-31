#include<stdio.h>

struct process
{
	int id;
	int btime;
	int artime;
	int wtime;
	int ttime;
	int temp;
};

int main()
{
	int n,time,end,count=0,small;
	struct process p[10];
	printf("Enter number of proceses: ");
	scanf("%d",&n);
	printf("Enter details:\n");
	for(int i=0;i<n;i++) 
	{
		p[i].id=i;
		printf("p%d bursttime:",i);
		scanf("%d",&(p[i].btime));
		printf("p%d arrival time:",i);
		scanf("%d",&(p[i].artime));
		p[i].temp = p[i].btime;
	}
	
	p[9].btime = 10000;
	small=9;
	printf("0");
	for(time=0;count<n;time++)
	{
		
		
		for(int i=0;i<n;i++)
		{
			if((p[i].artime <= time) && (p[i].btime < p[small].btime) && (p[i].btime > 0))
			{
				small = i;
			}
		}
		p[small].btime = p[small].btime-1;
		
		if(p[small].btime == 0)
		{
			end = time+1;
			count++;
			p[small].wtime = end-p[small].temp-p[small].artime;
			p[small].ttime = p[small].wtime+p[small].temp;
			small = 9;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		printf("p%d \twtime:%d \tttime:%d\n",p[i].id,p[i].wtime,p[i].ttime);
	}
	
	return 0;
}

















