/* Roll No: B20CSB65
   Name: Sreekanth cs
   Name of the Experiment: Page replacement algorithms fifo,lru,lfu*/

#include<stdio.h>

int page[30],nf,np;


void fifo()
{
	printf("\nFifo\n");
	float hit=0;
	int frame[30],miss=0;
	for(int i=0;i<nf;i++)
		frame[i]=-1;
	
	int n=0,in=0;
	for(int i=0;i<np;i++)
	{
		int flag=0;
		for(int j=0;j<n;j++)
		{
			if(page[i] == frame[j])
			{
				hit++;
				flag=1;
				for(int k=0;k<nf;k++)
					printf("%d  ",frame[k]);
				printf("\n");
				break;
			}
				
				
		}
		if(flag==1)
			continue;
		if(n<nf)
		{
			frame[in%nf] = page[i];
			in++;
			n++;
			miss++;
		}
		else
		{
			frame[in%nf] = page[i];
			in++;
			miss++;
		}
		
		for(int k=0;k<nf;k++)
			printf("%d  ",frame[k]);
		printf("\n");
	}
	printf("Hit=%f  Miss=%d  Hit ratio=%f\n",hit,miss,(hit/np));
}


void lru()
{
	printf("\nLru\n");
	float hit=0;
	int frame[30],miss=0;
	for(int i=0;i<nf;i++)
		frame[i]=-1;
	int q[30],n=0,in=0;
	for(int i=0;i<np;i++)
	{
		int flag=0;
		for(int j=0;j<n;j++)
		{
			if(page[i] == frame[j])
			{
				
				hit++;
				flag=1;
				int v;
				for(v=0;v<n;v++)
				{
					if(q[v]==j)
					{
						break;
					}
				}
				for(int f=v;f<n-1;f++)
				{
					q[f] = q[f+1];
				}
				q[n-1] = j;
				for(int k=0;k<nf;k++)
					printf("%d  ",frame[k]);
				printf("\n");
				break;
			}
				
				
		}
		if(flag==1)
			continue;
		if(n<nf)
		{
			q[in%nf] = in%nf; 
			frame[in%nf] = page[i];
			in++;
			n++;
			miss++;
		}
		else
		{
			in = q[0];
			frame[in%nf] = page[i];
			for(int v=0;v<nf-1;v++)
			{
				q[v] = q[v+1];
			}
			q[nf-1] = in%nf;
			miss++;
		}
		
		for(int k=0;k<nf;k++)
			printf("%d  ",frame[k]);
		printf("\n");
	}
	printf("Hit=%f  Miss=%d  Hit ratio=%f\n",hit,miss,(hit/np));
}


void lfu()
{
	printf("\nLfu\n");
	struct frame
	{
		int val;
		int fr;
	}frames[30];
	float hit=0;
	int miss=0,q[30];
	for(int i=0;i<nf;i++)
	{
		frames[i].val=-1;
		frames[i].fr = 0;
	}
	
	int n=0,in=0;
	for(int i=0;i<np;i++)
	{
		int flag=0;
		for(int j=0;j<n;j++)
		{
			if(page[i] == frames[j].val)
			{
				hit++;
				flag=1;
				frames[j].fr++;
				int v;
				for(v=0;v<n;v++)
				{
					if(q[v]==j)
						break;
				}
				for(int f=v;f<n-1;f++)
				{
					q[f] = q[f+1];
				}
				q[n-1] = j;
				for(int k=0;k<nf;k++)
					printf("%d  ",frames[k].val);
				printf("\n");
				break;
			}
				
				
		}
		if(flag==1)
			continue;
		if(n<nf)
		{
			frames[in%nf].val = page[i];
			frames[in%nf].fr++;
			q[in%nf]=in%nf;
			in++;
			n++;
			miss++;
		}
		else
		{
			
			int lfr=q[0];
			for(int v=0;v<n;v++)
			{
				int index=q[v];              //this line added last not tested    remove ine if error
				if(frames[index].fr<frames[lfr].fr)   //if error change index with v
				{
					lfr=index;
				}
			}
			frames[lfr].val=page[i];
			frames[lfr].fr = 1;
			int v;
			for(v=0;v<n;v++)
			{
				if(lfr==q[v])
					break;
			}
			for(int f=v;f<n-1;f++)
			{
				q[f] = q[f+1];
			}
			q[n-1]=lfr;
			miss++;
		}
		
		for(int k=0;k<nf;k++)
			printf("%d  ",frames[k].val);
		printf("\n");
	}
	printf("Hit=%f  Miss=%d  Hit ratio=%f\n",hit,miss,(hit/np));
}


int main()
{
	
	printf("\nEnter the number of Pages:\t");
	scanf("%d", &np);
	printf("\nEnter reference string values:\n");
	for(int m = 0; m < np; m++)
	{
	   printf("Value No. [%d]:\t", m + 1);
	   scanf("%d", &page[m]);
	}
	printf("\n What are the total number of frames:\t");
	scanf("%d", &nf);
	fifo();
	lru();
	lfu();
	
	return 0;	
}







