/* PROGRAM 34 : CONTIGUOUS FILE ALLOCATION */

#include <stdio.h>

int main() {
    int files[20] = {0}, start, length, i, flag = 0;

    printf("Enter start block: ");
    scanf("%d", &start);
    printf("Enter length: ");
    scanf("%d", &length);

    for(i=start;i<start+length;i++) {
        if(files[i] == 1) {
            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        for(i=start;i<start+length;i++)
            files[i] = 1;
        printf("File allocated.\n");
    } else {
        printf("Cannot allocate. Block occupied.\n");
    }
    return 0;
}
