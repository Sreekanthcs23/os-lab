#include<stdio.h>

int main() 
{
	int n,request[20],direction,head,index,disksize,seektime;
	printf("Enter number of requests:");
	scanf("%d",&n);
	printf("Enter requests:");
	for(int i=0;i<n;i++) 
	{
		scanf("%d",&request[i]);
	}
	printf("Enter the direction 1-right  2-left:");
	scanf("%d",&direction);
	printf("Enter head position:");
	scanf("%d",&head);
	printf("Enter disksize:");
	scanf("%d",&disksize);
	
	
	for(int i=0;i<n;i++)
	{
		if(request[i] < head && request[i+1] >= head)
		{
			index = i;
		}
	}
	
	if(direction == 1) 
	{
		for(int i=index+1;i<n;i++) 
		{
			printf("%d  ",request[i]); 
		}
		seektime = (request[n-1]-head);
		if(request[0] < head) 
		{
			for(int i=index;i>=0;i--)
				printf("%d  ",request[i]);
			seektime = (disksize-1)-head+(disksize-1)-request[0];
		}
	}
}








