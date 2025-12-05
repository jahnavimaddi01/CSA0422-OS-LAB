/* PROGRAM 35 : INDEXED FILE ALLOCATION */

#include <stdio.h>

int main() {
    int block[50] = {0}, index, n, i, b;

    printf("Enter index block: ");
    scanf("%d", &index);

    if(block[index] == 1) {
        printf("Index block already allocated\n");
        return 0;
    }

    block[index] = 1;

    printf("Enter number of blocks needed: ");
    scanf("%d", &n);

    printf("Enter blocks: ");
    for(i=0;i<n;i++) {
        scanf("%d", &b);
        if(block[b] == 0) {
            block[b] = 1;
            printf("Block %d allocated\n", b);
        } else {
            printf("Block %d already allocated\n", b);
        }
    }
    return 0;
}
