// Program 14: Optimal Page Replacement
#include <stdio.h>

int main() {
    int pages[30], frame[10], n, f, i, j, k, faults = 0, found, pos, farthest;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    printf("Enter reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        found = 0;
        for(j = 0; j < f; j++)
            if(frame[j] == pages[i])
                found = 1;

        if(!found) {
            if(i < f)
                frame[i] = pages[i];
            else {
                farthest = -1;
                pos = -1;
                for(j = 0; j < f; j++) {
                    for(k = i + 1; k < n; k++) {
                        if(frame[j] == pages[k]) {
                            if(k > farthest) {
                                farthest = k;
                                pos = j;
                            }
                            break;
                        }
                    }
                    if(k == n) {
                        pos = j;
                        break;
                    }
                }
                frame[pos] = pages[i];
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

