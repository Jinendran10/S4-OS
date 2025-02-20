#include <stdio.h>

void main() {
    int n, i, j, time = 0, count = 0, tq;
    int at[10], bt[10], wt[10], tt[10], temp[10], remaining_bt[10];

    double avg_wt = 0, avg_tt = 0;

    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

   
    for (i = 0; i < n; i++) {
        printf("\nP%d: Enter the Arrival Time and Burst Time: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        temp[i] = bt[i]; 
        remaining_bt[i] = bt[i];
    }

   
    printf("Enter the time quantum: ");
    scanf("%d", &tq);

   
    printf("\nProcess\tAT\tBT\tWT\tTAT\n");

    while (count < n) {
      
        for (i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                if (remaining_bt[i] > tq) {
                    time += tq;
                    remaining_bt[i] -= tq;
                } else {
                    time += remaining_bt[i];
                    wt[i] = time - at[i] - temp[i]; 
                    tt[i] = wt[i] + temp[i]; 
                    count++;
                    remaining_bt[i] = 0; 
                }
            }
        }
    }

    
    for (i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tt += tt[i];
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], temp[i], wt[i], tt[i]);
    }

    
    avg_wt /= n;
    avg_tt /= n;

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f", avg_tt);
}

