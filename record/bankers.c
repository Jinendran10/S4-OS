#include<stdio.h>
void main(){
	int n,i,j,available[100],need[100][100],p[100],allocation[100][100],max[100][100],m;
	printf("Enter the no.of processes:");
	scanf("%d",&n);
	printf("Enter the no.of resources:");
	scanf("%d",&m);
	int safe[n],finish=0,k=1,flag=1;
	for(i=0;i<n;i++){
		printf("\nEnter the resource allocated and maximum resources of process P%d:",i+1);
		p[i]=i+1;
		for(j=0;j<m;j++){
			printf("\nEnter the allocation of resource %d in process P%d:",j+1,i+1);
			scanf("%d",&allocation[i][j]);
			printf("\nEnter the maximum allocation of resource %d in process P%d:",j+1,i+1);
			scanf("%d",&max[i][j]);
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}
	for(i=0;i<n;i++){
		printf("\n Need of resource %d:",i);
		for(j=0;j<m;j++){
			printf("\n%d",need[i][j]);
		}
	}
	for(j=0;j<m;j++){
		printf("\nEnter the available resource %d:",j+1);
		scanf("%d",&available[j]);
	}
	for(i=0;i<m;i++){
		printf("Available\n---------------------------------------------------------\n");
		printf("%d\n",available[i]);
	}
	while(finish<n||flag==0){
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				while(j<m){	
					j++;
					if(need[i][j]<=available[j]){
						continue;
					}
					else{
						k=0;
						break;
					}				
				}
				if(finish==n-1){
					if(k!=0){
					allocation[i][j]+=need[i][j];
					available[j]-=need[i][j];
					available[j]+=allocation[i][j];
					allocation[i][j]=0;
					finish++;
					safe[finish]=p[i];
					}
					else{
						flag=0;
						break;
					}
				}
				else{
					if(k!=0){
					allocation[i][j]+=need[i][j];
					available[j]-=need[i][j];
					available[j]+=allocation[i][j];
					allocation[i][j]=0;
					finish++;
					safe[finish]=p[i];
					}
					else{
						continue;
					}
				}
			}
			printf("%d",flag);
			if(flag==0){
				printf("Not safe sequence!\n");
				break;
			}
			else{
				printf("Safe sequence!\n");
				printf("The safe sequence is:\n");
				for(i=0;i<n;i++){
					printf("%d",safe[i]);
				}
			}
		}
	}
	printf("The Algortithm table is:\n");
	printf("Process\tAllocation\tMax\tNeed\n");
	printf("--------------------------------");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("\n%d\t%d\t%d\t%d\t",p[i],allocation[i][j],max[i][j],need[i][j]);
		}
	}
	
}





