#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main() 
{
	int fd1 = open("prg1.c",O_RDONLY);
	int fd2 = open("test.c",O_WRONLY);
	char buf[20];
	int sizeRead = read(fd1,buf,20);
	int sizeWritten = write(fd2,buf,20);
	printf("%s",buf);
	close(fd1);
	close(fd2);
	return 0; 
}

