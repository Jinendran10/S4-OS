#include <stdio.h>

void main() {
    int n, i, j, temp, time = 0;
    int at[10], bt[10], wt[10], tt[10], st[10];
    double avg_wt = 0, avg_tt = 0;

   
    printf("Enter the number of processes: ");
    scanf("%d", &n);


    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
    }

   
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

         
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
            }
        }
    }

    wt[0] = 0; 
    tt[0] = bt[0];

    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j]; 
        }
        tt[i] = wt[i] + bt[i]; 
    }

    for (i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tt += tt[i];
    }

    avg_wt /= n;
    avg_tt /= n;


    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tt[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f", avg_tt);
}

