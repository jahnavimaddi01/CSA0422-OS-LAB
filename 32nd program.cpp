/* PROGRAM 32 : BANKER'S ALGORITHM */

#include <stdio.h>

int main() {
    int n, m, alloc[10][10], max[10][10], avail[10];
    int need[10][10], finish[10] = {0}, seq[10];
    int i, j, k, count = 0, safe;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter allocation matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter max matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    printf("Enter available resources: ");
    for(i=0;i<m;i++)
        scanf("%d",&avail[i]);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    while(count < n) {
        safe = 0;
        for(i=0;i<n;i++) {
            if(!finish[i]) {
                for(j=0;j<m;j++)
                    if(need[i][j] > avail[j]) break;

                if(j == m) {
                    for(k=0;k<m;k++)
                        avail[k] += alloc[i][k];
                    finish[i] = 1;
                    seq[count++] = i;
                    safe = 1;
                }
            }
        }
        if(!safe) break;
    }

    if(count == n) {
        printf("Safe Sequence: ");
        for(i=0;i<n;i++)
            printf("P%d ", seq[i]);
    } else {
        printf("No Safe Sequence");
    }

    return 0;
}
