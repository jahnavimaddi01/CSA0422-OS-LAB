// Program 15: First Fit
#include <stdio.h>

int main() {
    int b, p, i, j;
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
        for(j = 0; j < b; j++) {
            if(block[j] >= process[i]) {
                printf("%d\t%d\n", process[i], j+1);
                block[j] -= process[i];
                break;
            }
        }
        if(j == b) printf("%d\tNot Allocated\n", process[i]);
    }
    return 0;
}

