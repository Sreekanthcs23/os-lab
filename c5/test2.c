/* Roll No: B20CSB65
   Name: Sreekanth cs
   Name of the Experiment: Memory allocation first fit,best fit,worst fit */

#include<stdio.h>

struct process
{
	int request;
	int blockno;
};

struct memory
{
	int size;
	int flag;
};

struct process p1[20];
struct memory m1[20];

int np,nm;

void ffit()
{
	struct process p[20];
	struct memory m[20];
	for(int i=0;i<np;i++)
		p[i] = p1[i];
	for(int i=0;i<nm;i++)
		m[i] = m1[i];
	
	int lastAllocated=-1;
	for(int i=0;i<np;i++)
	{
		int j = lastAllocated+1;
		for(int k=0;k<nm;k++)
		{
			if(p[i].request<=m[(j%nm)].size && m[(j%nm)].flag==0)
			{
				p[i].blockno = (j%nm)+1;
				m[(j%nm)].flag=1;
				m[(j%nm)].size-=p[i].request;
				lastAllocated = j;
				break;
			}
			j++;
		}
	}
	
	printf("\nFirst fit:\n");
	for(int i=0;i<np;i++)
	{
		if(p[i].blockno==-1)
			printf("process %d  Not allocated\n",i+1);
		else
			printf("process %d  blockno:%d\n",i+1,p[i].blockno);
	}
	
	printf("\nRemaining:\n");
	for(int i=0;i<nm;i++)
	{
		printf("Block %d: %d\n",i+1,m[i].size);
		
	}
	
}


void bfit()
{
	struct process p[20];
	struct memory m[20];
	for(int i=0;i<np;i++)
		p[i] = p1[i];
	for(int i=0;i<nm;i++)
		m[i] = m1[i];
	
	for(int i=0;i<np;i++)
	{
		int small = 10000,in;
		for(int j=0;j<nm;j++)
		{
			if(p[i].request<=m[j].size && m[j].size<small && m[j].flag==0) 
			{
				small = m[j].size;
				in = j;
			}
		}
		
		if(small!=10000)
		{
			p[i].blockno = in+1;
			m[in].flag=1;
			m[in].size-=p[i].request;
		}
	}
	
	printf("\nBest fit:\n");
	for(int i=0;i<np;i++)
	{
		if(p[i].blockno==-1)
			printf("process %d  Not allocated\n",i+1);
		else
			printf("process %d  blockno:%d\n",i+1,p[i].blockno);
	}
	
	printf("\nRemaining:\n");
	for(int i=0;i<nm;i++)
	{
		printf("Block %d: %d\n",i+1,m[i].size);
		
	}
}


void wfit()
{
	struct process p[20];
	struct memory m[20];
	for(int i=0;i<np;i++)
		p[i] = p1[i];
	for(int i=0;i<nm;i++)
		m[i] = m1[i];

	for(int i=0;i<np;i++)
	{
		int large = -1,in;
		for(int j=0;j<nm;j++)
		{
			if(p[i].request<=m[j].size && m[j].size>large && m[j].flag==0) 
			{
				large = m[j].size;
				in = j;
			}
		}
		
		if(large!=-1)
		{
			p[i].blockno = in+1;
			m[in].flag=1;
			m[in].size-=p[i].request;
		}
	}
	
	printf("\nWorst fit:\n");
	for(int i=0;i<np;i++)
	{
		if(p[i].blockno==-1)
			printf("process %d  Not allocated\n",i+1);
		else
			printf("process %d  blockno:%d\n",i+1,p[i].blockno);
	}
	
	printf("\nRemaining:\n");
	for(int i=0;i<nm;i++)
	{
		printf("Block %d: %d\n",i+1,m[i].size);
		
	}
}

int main()
{
	
	
	
	printf("Enter number of memory blocks:");
	scanf("%d",&nm);
	printf("Enter memory blocks:");
	for(int i=0;i<nm;i++)
	{
		scanf("%d",&(m1[i].size));
		m1[i].flag=0;
	}
	printf("\nEnter number of processes:");
	scanf("%d",&np);
	printf("Enter process requests:");
	for(int i=0;i<np;i++)
	{
		scanf("%d",&(p1[i].request));
		p1[i].blockno=-1;
	}
	
	ffit();
	bfit();
	wfit();
	
	
	
	return 0;
}
















