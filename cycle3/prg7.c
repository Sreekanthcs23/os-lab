/* Roll No: B20CSB65
   Name: Sreekanth cs
   Name of the Experiment: Round Robin Scheduling */

#include<stdio.h>

struct process
{
	int id;
	int btime;
	int artime;
	int wtime;
	int ttime;
	int temp;
}p[20];

int n;
float sum=0,totalw=0,totalt=0;

void rr(int slice)
{
	int time = 0,count=0;
	printf("0");
	for(int i=0;count<n;i++)
	{
		int j = i%n;
		if((p[j].artime <= time) && (p[j].btime>0))
		{
			if(p[j].btime<slice)
			{
				time = time+p[j].btime;
				p[j].btime = 0;
				
			}
			if(p[j].btime >= slice)
			{
				p[j].btime-=slice;
				time+=slice;
			}
			if(p[j].btime==0)
			{
				count++;
				p[j].wtime = time - p[j].temp - p[j].artime;
				p[j].ttime = p[j].wtime + p[j].temp;
			}
			printf("-P%d-%d",p[j].id,time);
		}
	}
	printf("\n");
	for(int i=0;i<n;i++)
	{
		p[i].btime = p[i].temp;
		printf("p%d \twtime:%d \tttime:%d\n",p[i].id,p[i].wtime,p[i].ttime);
		totalw+=p[i].wtime;
		totalt+=p[i].ttime;
	}
	
	printf("\nAverage waiting time: %f\nAverage turn around time: %f\nThroughput: %f\n",(totalw/n),(totalt/n),(n/sum));
}

int main()
{
	int op;
	char ch;
	printf("Enter number of proceses: ");
	scanf("%d",&n);
	printf("Enter details:\n");
	for(int i=0;i<n;i++) 
	{
		printf("p%d bursttime:",i);
		scanf("%d",&(p[i].btime));
		printf("p%d arrival time:",i);
		scanf("%d",&(p[i].artime));
		p[i].temp = p[i].btime;
		p[i].id = i;
		sum+=p[i].btime;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(p[j].artime > p[j+1].artime)
			{
				struct process temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	
	printf("1. 2ms\n2. 4ms\n3. 8ms\n4. 10ms\n");
	
	do
	{
		printf("Enter option:");
		scanf("%d",&op);
		switch(op)
		{
			case 1: rr(2);
				break;
			case 2: rr(4);
				break;
			case 3: rr(8);
				break;
			case 4: rr(10);
				break;
		}
		printf("Enter n to stop:");
		scanf(" %c",&ch);
	}while(ch!='n');
	
	
	
	return 0;
}

















