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
    void * shared_memory;
    char buff[100];
    int shmid;
    int n=3,i;
    shmid=shmget((key_t)1122,1024,0666);
    printf("Key of shared memory is %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("Process attached at %p\n",shared_memory);
    //printf("Enter data to write in shared memory\n");
   // read(0,buff,100);
    //strcpy(shared_memory,buff);
    printf("Data read from shared memory is \n");
    struct student s = *(struct student *)shared_memory;
    for(i=0;i<n;i++)
    {
        
        printf("Student %d\n name=%s\nmark=%d\n\n",i+1,s.name,s.mark);
        shared_memory++;
    }
}
