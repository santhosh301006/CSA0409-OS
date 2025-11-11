#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];
    float avgwt = 0, avgtat = 0;

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) scanf("%d", &bt[i]);

    // Sort processes by burst time (SJF)
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(bt[i] > bt[j]) {
                int t = bt[i];
                bt[i] = bt[j];
                bt[j] = t;
            }

    wt[0] = 0; // first process has no waiting time
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nP\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nAverage WT = %.2f", avgwt/n);
    printf("\nAverage TAT = %.2f\n", avgtat/n);

    return 0;
}


