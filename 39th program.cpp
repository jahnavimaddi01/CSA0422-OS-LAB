/* PROGRAM 39 : SCAN DISK SCHEDULING */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, req[20], temp;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests: ");
    for(i=0;i<n;i++) scanf("%d",&req[i]);

    printf("Enter head position: ");
    scanf("%d", &head);

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(req[j] < req[i]) {
                temp = req[i]; req[i] = req[j]; req[j] = temp;
            }

    int total = 0, pos = 0;

    for(i=0;i<n;i++)
        if(req[i] > head) { pos = i; break; }

    for(i=pos;i<n;i++) {
        total += abs(req[i] - head);
        head = req[i];
    }

    for(i=pos-1;i>=0;i--) {
        total += abs(req[i] - head);
        head = req[i];
    }

    printf("Total Head Movement = %d\n", total);
    return 0;
}
