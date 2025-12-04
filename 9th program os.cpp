// Program 9: C-SCAN Disk Scheduling
#include <stdio.h>

int main() {
    int queue[20], head, i, j, n, temp, total = 0, size;
    
    printf("Enter disk size: ");
    scanf("%d", &size);
    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);
    
    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Sorting
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    printf("\nOrder of head movement:\n%d", head);

    // Move right
    for(i = 0; i < n; i++) {
        if(queue[i] >= head) {
            total += queue[i] - head;
            head = queue[i];
            printf(" -> %d", head);
        }
    }

    // Jump to 0
    total += (size - 1) - head;
    head = 0;
    total += head;
    printf(" -> 0");

    // Move right again
    for(i = 0; i < n; i++) {
        if(queue[i] < head) continue;
        total += queue[i] - head;
        head = queue[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Head Movement = %d\n", total);
    return 0;
}

