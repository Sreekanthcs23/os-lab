#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
struct student
{
    char name[30];
    int mark;
}s;
void main()
{
    int i;
    void * shared_memory;
    int n;
    int shmid;
    shmid=shmget((key_t)1122,1024,0666|IPC_CREAT);
    printf("Key of shared memory is %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("Process attached at %p\n",shared_memory);
    printf("Enter no of students\n");
    scanf("%d",&n);
    struct  student * temp=(struct student *)shared_memory;
    for(i=0;i<n;i++)
    {
        printf("Enter name\n");
        scanf("%s",s.name);
        printf("Enter mark\n");
        scanf("%d",&s.mark);
        * temp= s;
        temp++;
    }
   // printf("Enter data to write in shared memory\n");
  //  read(0,buff,100);
   // strcpy(shared_memory,buff);
   // printf("You wrote %s\n",(char *)shared_memory);
}
