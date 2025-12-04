/* PROGRAM 26 : FIFO QUEUE IMPLEMENTATION */

#include <stdio.h>

int main() {
    int queue[10], front = 0, rear = -1, n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter values: ");
    for(i=0;i<n;i++) {
        scanf("%d", &queue[++rear]);
    }

    printf("Queue Output: ");
    for(i=front;i<=rear;i++) {
        printf("%d ", queue[i]);
    }
    return 0;
}
