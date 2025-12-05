/* PROGRAM 31 : PRIORITY SCHEDULING (NON-PREEMPTIVE) */

#include <stdio.h>

int main() {
    int n, bt[10], pr[10], wt[10], tat[10], i, j, temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times: ");
    for(i=0;i<n;i++) scanf("%d",&bt[i]);

    printf("Enter priorities: ");
    for(i=0;i<n;i++) scanf("%d",&pr[i]);

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(pr[j] < pr[i]) {
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
            }

    wt[0] = 0;
    for(i=1;i<n;i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(i=0;i<n;i++)
        tat[i] = wt[i] + bt[i];

    printf("P\tBT\tPR\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], pr[i], wt[i], tat[i]);

    return 0;
}
