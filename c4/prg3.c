#include<stdio.h>
struct process
{
    int allo[5];
    int max[4];
    int need[4];
    int flag;
};

int main()
{
    int i,j,k,l,n,avail[5],cycle=0,arr[10],z=0,DL=0;
    struct process p[10];
    printf("Enter the no of process\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the details of process %d\n",i);
        printf("Enter the allocated resources for A,B&C for process %d\n",i);
        for(j=0;j<3;j++)
        {
            scanf("%d",&p[i].allo[j]);
        }
        printf("Enter the max resources needed for A,B&C for process %d\n",i);
        for(k=0;k<3;k++)
        {
            scanf("%d",&p[i].max[k]);
        }
        for(l=0;l<3;l++)
        {
            p[i].need[l]=p[i].max[l]-p[i].allo[l];
        }
        p[i].flag=0;
    }
    printf("Enter the available resources for A,B &C\n");
    for(i=0;i<3;i++)
    {
        scanf("%d",&avail[i]);
    }
    printf("ALLOCATION\n");
    printf("  A    B    C\n");
    for(i=0;i<n;i++)
    {
        printf("p%d  ",i);
        for(j=0;j<3;j++)
        {
            printf("%d    ",p[i].allo[j]);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("MAX\n");
    printf("  A    B    C\n");
    for(i=0;i<n;i++)
    {
        printf("p%d  ",i);
        for(j=0;j<3;j++)
        {
            printf("%d    ",p[i].max[j]);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("NEED\n");
    printf("  A    B    C\n");
    for(i=0;i<n;i++)
    {
        printf("p%d  ",i);
        for(j=0;j<3;j++)
        {
            printf("%d    ",p[i].need[j]);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("AVIALABLE\n");
    printf("A    B    C\n");
    for(j=0;j<3;j++)
    {
            printf("%d    ",avail[j]);
    }
   while(cycle<3)
    {
        for(i=0;i<n;i++)
        {
            j=0;
            if(p[i].need[j]<=avail[j]&&p[i].need[j+1]<=avail[j+1]&&p[i].need[j+2]<=avail[j+2]&&p[i].flag==0)
            {
               avail[j]= avail[j]+p[i].allo[j];
               avail[j+1]= avail[j+1]+p[i].allo[j+1];
               avail[j+2]= avail[j+2]+p[i].allo[j+2];
               p[i].flag=1;
               arr[z]=i;
               z++;
            }

        }
        cycle++;
    }
    for(i=0;i<n;i++)
    {
        if(p[i].flag==0)
            DL=1;
    }
    if(DL==1)
    {
        printf("\nProcess cannot be arranged in a way to aviod deadlock\n");
    }
    else
    {
        printf("TOTAL AVIALABLE\n");
        printf("A    B    C\n");
        for(j=0;j<3;j++)
        {
            printf("%d    ",avail[j]);
        }
        printf("Process can be arranged in a way to aviod deadlock\n");
        printf("ARRANGEMENT\n");
        for(i=0;i<z;i++)
        {
            printf("P%d - ",arr[i]);
        }
    }
}
