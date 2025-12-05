/* PROGRAM 36 : LINKED FILE ALLOCATION */

#include <stdio.h>

int main() {
    int block[50] = {0}, start, next, i, n;

    printf("Enter starting block: ");
    scanf("%d", &start);

    if(block[start] == 1) {
        printf("Already allocated\n");
        return 0;
    }

    block[start] = 1;

    printf("Enter number of blocks to link: ");
    scanf("%d", &n);

    for(i=0;i<n;i++) {
        printf("Enter next block: ");
        scanf("%d", &next);

        if(block[next] == 0) {
            block[next] = 1;
            printf("Block %d linked\n", next);
        } else {
            printf("Already allocated\n");
        }
    }
    return 0;
}
