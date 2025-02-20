#include <stdio.h>

void main() {
    int n, i, j, temp;
    int at[10], bt[10], wt[10], tt[10], priority[10];
    double avg_wt = 0, avg_tt = 0;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input Arrival Time (AT), Burst Time (BT), and Priority for each process
    for (i = 0; i < n; i++) {
        printf("\nEnter Arrival Time, Burst Time, and Priority for Process P%d: ", i + 1);
        scanf("%d%d%d", &at[i], &bt[i], &priority[i]);
    }

    // Sorting processes based on their priority (ascending order)
    // If two processes have the same priority, they are sorted by arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (priority[i] > priority[j] || (priority[i] == priority[j] && at[i] > at[j])) {
                // Swap burst times
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap arrival times
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap priorities
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
            }
        }
    }

    // Calculate Waiting Time (WT) and Turnaround Time (TAT)
    wt[0] = 0;  // First process has no waiting time
    tt[0] = bt[0];  // Turnaround time is equal to burst time for the first process

    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];  // Sum the burst times of all previous processes
        }
        tt[i] = wt[i] + bt[i];  // Turnaround time = waiting time + burst time
    }

    // Calculate the average waiting time and average turnaround time
    for (i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tt += tt[i];
    }

    avg_wt /= n;
    avg_tt /= n;

    // Output the result
    printf("\nProcess\tAT\tBT\tPriority\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n", i + 1, at[i], bt[i], priority[i], wt[i], tt[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f", avg_tt);
}

