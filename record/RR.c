#include<stdio.h>
void main(){
	int i,n,at[10],bt[10],wt[10],tt[10],temp[10],m,time=0,count=0,tq,t,rq[100];
	double avg_tt=0,avg_wt=0,end=0;
	printf("Enter the no.of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nP%d:",i+1);
		printf("Enter the AT & BT of the process:");
		scanf("%d%d",&at[i],&bt[i]);
		temp[i]=bt[i];
	}
	printf("Enter the time quantum:");
	scanf("%d",&tq);
	bt[9]=9876;
	for(i=0;i<n;i++){
		if(at[i]>at[i+1]){
			t=at[i];
			at[i]=at[i+1];
			at[i+1]=t;
		}
	}
	rq[i]=
	while(count!=n){
		for(i=0;i<n;i++){
			if(bt[i]>=tq && bt[i]>0){
				bt[i]-=tq;
				time+=tq	
			}
			else{	
				time+=bt[i];
				bt[i]=0;
				count++;
			}
			
						
				
				
		
		
		
		
				
		
