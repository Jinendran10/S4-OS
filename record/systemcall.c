#include<fcntl.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
void main(){
	int fd,fd2;
	char wbuf[128];
	char rbuf[128];
	fd=open("file.txt",O_RDWR);
	printf("Enter the text:");
	scanf("%s",wbuf);
	write(fd,wbuf,strlen(wbuf));
	close(fd);
	fd2=open("file.txt",O_RDWR);
	printf("The conten ts are:");
	read(fd2,rbuf,100);
	printf("%s",rbuf);
	close(fd2);
}
