// Program 16: Best Fit
#include <stdio.h>

int main() {
    int b, p, i, j, best;
    int block[20], process[20];

    printf("Enter number of blocks: ");
    scanf("%d", &b);
    printf("Enter block sizes: ");
    for(i = 0; i < b; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter process sizes: ");
    for(i = 0; i < p; i++)
        scanf("%d", &process[i]);

    printf("\nProcess\tBlock\n");
    for(i = 0; i < p; i++) {
        best = -1;
        for(j = 0; j < b; j++)
            if(block[j] >= process[i])
                if(best == -1 || block[j] < block[best])
                    best = j;
        
        if(best != -1) {
            printf("%d\t%d\n", process[i], best+1);
            block[best] -= process[i];
        } else {
            printf("%d\tNot Allocated\n", process[i]);
        }
    }
    return 0;
}

