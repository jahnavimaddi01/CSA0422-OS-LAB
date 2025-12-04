/* PROGRAM 27 : STACK IMPLEMENTATION */

#include <stdio.h>

int main() {
    int stack[10], top = -1, n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter values: ");
    for(i=0;i<n;i++) {
        scanf("%d", &stack[++top]);
    }

    printf("Stack Pop Order: ");
    while(top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
