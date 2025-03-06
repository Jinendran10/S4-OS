#include<stdio.h>
#include<stdlib.h>
int full=0,empty=3,mutex=1,x=0;
int signal(int s){
	return(++s);
}
int wait(int s){
	return(--s);
}
void producer(){
	empty=wait(empty);
	mutex=wait(mutex);
	x++;
	printf("The producer produced the item:%d",x);
	mutex=signal(mutex);
	full=signal(full);
}
void consumer(){
	full=wait(full);
	mutex=wait(mutex);
	x--;
	printf("The Consumer consumed the item:%d",x);
	empty=signal(empty);
	mutex=signal(mutex);
}
void main(){
	int ch;
	while(1){
		printf("Enter your choice:\n1.Producer\n2.Consumer\n3.exit");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				if((mutex==1) &&(empty!=0)){
					producer();
				}
				else{
					printf("\nBUFFER is FULL");
				}
				break;
			case 2:
				if((mutex==1) && (full!=0)){
					consumer();
				}
				else
					printf("BUFFER is empty!");
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("Invalid choice!");
		}
	}
}
		
			
	
