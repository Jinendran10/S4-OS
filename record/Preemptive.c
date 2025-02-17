#include<stdio.h>
void main(){
	int i,n,at[10],bt[10],wt[10],ct[10],tt[10],temp[10],pr[10],p[10],smallest,count=0,time;
	double avg_wt=0,avg_tt=0,end=0;
	printf("Enter the no.of processes:");
	scanf("%d",&n);
	printf("Enter the arrivial time and bt and priority of the process\n");
	for(i=0;i<n;i++){
		printf("P%d ",i+1);
		scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
		temp[i]=bt[i];
	}
	pr[9]=9876;
	for(time=0;count!=n;time++){
		smallest=9;
		for(i=0;i<n;i++){
			if(at[i]<=time&&pr[i]<pr[smallest]&&bt[i]>0){
				smallest=i;
			}
		}		
		bt[smallest]--;
		if(bt[smallest]==0){
				count++;
				end=time+1;
		ct[smallest]=end;
		tt[smallest]=end-at[smallest];
		wt[smallest]=end-at[smallest]-temp[smallest];
		}
	}
	printf("\nAT\tBT\tTT\tpr\tWT");
	for(i=0;i<n;i++){
		printf("\n%d\t%d\t%d\t%d\t%d\t",at[i],temp[i],pr[i],tt[i],wt[i]);
		avg_wt+=wt[i];
		avg_tt+=tt[i];
	}
	printf("The average Waiting time is:%lf",avg_wt/n);
	printf("The average Turnaround time is:%lf",avg_tt/n);
}
	
