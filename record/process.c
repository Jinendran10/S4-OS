Program
#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
void main(){
	int status,pid,child_pid;
	pid=fork();
	if(pid==-1){
		printf("The parent process creation failed!");
		exit(0);
	}
	else if(pid==0){
		printf("The child process with the id is:%d\n",getpid());
		execlp("/bin/date","date",NULL);
		exit(0);
	}
	else{
		child_pid=wait(&status);
		printf("Inside parent process with id:%d\n",getpid());
		printf("child process created");
		exit(0);
	}
}
