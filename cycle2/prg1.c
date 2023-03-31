/* Roll No: B20CSB65
   Name: Sreekanth cs
   Name of the Experiment: System call fork */

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

void fibanocci(int n)
{
	int term1 = 0;
	int term2 = 1;
	int term3;
	if(n<=0)
		return;
	if(n>=1)
		printf("Child: %d\n",term1);
	if(n>=2)
		printf("Child: %d\n",term2);
	for(int i=3;i<=n;i++)
	{
		term3 = term1+term2;
		printf("Child: %d\n",term3);
		term1=term2;
		term2=term3;
	}
}

void primeNumbers(int n)
{
	int c = 0;
	int t = 2;
	while(c<n)
	{
		int flag=1;
		for(int i=2;i<=(t/2);i++)
		{
			if(t%2==0)
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			printf("Parent: %d\n",t);
			c++;
		}
		t++;		
	}
}

int main()
{
	int n;
	printf("Enter n:");
	scanf("%d",&n);
	pid_t pid = fork();
	
	//error
	if(pid<0)
		perror("error");
	
	//child
	if(pid==0)
	{
		fibanocci(n);
		exit(0);
	}
	
	//parent
	wait(NULL);
	primeNumbers(n);
}
