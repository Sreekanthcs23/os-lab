#include<stdio.h>
#include<stdlib.h>

int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;
int arr[100];
int flag=0;

void input() {
    int i, j;
    printf("Enter the no of Processes\t");
    scanf("%d", &n);
    printf("Enter the no of resources instances\t");
    scanf("%d", &r);
    printf("Enter the Max Matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the Allocation Matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }

    }
    printf("Enter the available Resources\n");
    for (j = 0; j < r; j++) {
        scanf("%d", &avail[j]);
    }
}

void show() {
    int i, j;
    printf("Process\t Allocation\t Max\t Need\t Available");
    for (i = 0; i < n; i++) {
        printf("\nP%d\t ", i + 1);
        for (j = 0; j < r; j++) {
            printf("%d ", alloc[i][j]);
        }
        printf("\t");
        for (j = 0; j < r; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\t");
        for (j = 0; j < r; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\t");
        if (i == 0) {
            for (j = 0; j < r; j++)
                printf("%d ", avail[j]);
        }
    }
}

void cal() {

	int finish[100],c=0;
	int avail1[100];
	for (int i = 0; i < n; i++) {
		finish[i] = 0;
	}
	
	for(int i=0;i<r;i++)
	{
		avail1[i] = avail[i];
	}
	
	printf("\n");
	int z=0,c1,f=0;
	while(1)
	{
		for(int i=0;i<n;i++)
		{
			c1=0;
			f=0;
			for(int j=0;j<r;j++)
			{
				if(finish[i]==0 && need[i][j]<=avail1[j])
				{
					c1++;
					if(c1==r)
					{
						f++;
						for(int k=0;k<r;k++)
						{
							avail1[k]+=alloc[i][k];
						}
						finish[i] = 1;
						arr[z] = i;
						z++;
					}
				}
			}
		}
		if(f==0)
			break;
		c++;
	}
	
	if(z==n)
	{
		printf("\nSystem is in safe state\nSafe sequence: ");
		for(int i=0;i<z;i++)
		{
			printf("P%d-->",arr[i]);
		}
		printf("\n");
		flag=1;
	}
	else
	{
		printf("System is not in safe state\n");
		flag=0;
	}
}

void request() {
    	int pid, request[100];
        printf("\n Enter process number : ");
        scanf("%d", &pid);
        printf("\n Enter additional request : \n");
        for (int i = 0; i < r; i++) {
            printf(" Request for resource %d : ", i + 1);
            scanf("%d", &request[i]);
        }
        for (int i = 0; i < r; i++) {
            if (request[i] > need[pid][i]) {
                printf("\n ******Error encountered******\n");
                exit(0);
            }
        }
        for (int i = 0; i < r; i++) {

            avail[i] -= request[i];
            alloc[pid][i] += request[i];
            need[pid][i] -= request[i];
        }
        cal();
        if(flag==0)
        {
            printf("\nMay result in unsafe state Resource not granted\n");
            for (int i = 0; i < r; i++) {
		    avail[i] += request[i];
		    alloc[pid][i] -= request[i];
		    need[pid][i] += request[i];
            }
        }
        else
        {
        	printf("\nResource is granted\n");
        }
}


int main()
{
	char ch;
	input();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < r; j++) {
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	cal();
	show();
	do
	{
		
		request();
		printf("\nEnter y to request again:");
		scanf(" %c",&ch);
	}while(ch!='n');
	return 0;
}































