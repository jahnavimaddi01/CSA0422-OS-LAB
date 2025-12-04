// Program 7: FCFS Disk Scheduling
#include <stdio.h>

int main() {
    int queue[20], head, n, i, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nOrder of head movement:\n%d", head);

    for(i = 0; i < n; i++) {
        total += (queue[i] > head) ? (queue[i] - head) : (head - queue[i]);
        head = queue[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Head Movement = %d\n", total);

    return 0;
}

