/* PROGRAM 23 : FIRST FIT MEMORY ALLOCATION */

#include <stdio.h>

int main() {
    int block[10], process[10], nb, np, alloc[10], i, j;

    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    printf("Enter block sizes: ");
    for(i=0;i<nb;i++) scanf("%d",&block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);
    printf("Enter process sizes: ");
    for(i=0;i<np;i++) scanf("%d",&process[i]);

    for(i=0;i<np;i++) alloc[i] = -1;

    for(i=0;i<np;i++) {
        for(j=0;j<nb;j++) {
            if(block[j] >= process[i]) {
                alloc[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    for(i=0;i<np;i++) {
        printf("Process %d -> ", i+1);
        if(alloc[i] != -1) printf("Block %d\n", alloc[i]+1);
        else printf("Not Allocated\n");
    }
    return 0;
}
