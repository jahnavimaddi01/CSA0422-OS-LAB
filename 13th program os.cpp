// Program 13: LRU Page Replacement
#include <stdio.h>

int main() {
    int pages[30], frame[10], n, f, i, j, k, faults = 0, count[10], pos, found, least;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    printf("Enter reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frame[i] = -1;
        count[i] = 0;
    }

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        found = 0;
        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                count[j] = i;
                break;
            }
        }

        if(!found) {
            if(i < f)
                frame[i] = pages[i];
            else {
                least = 0;
                for(j = 1; j < f; j++)
                    if(count[j] < count[least])
                        least = j;

                frame[least] = pages[i];
                count[least] = i;
            }
            faults++;
        }

        printf("%d\t", pages[i]);
        for(j = 0; j < f; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}

