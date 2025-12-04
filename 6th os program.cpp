#include <stdio.h>

int main() {
    int n,i,j,t;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int pr[n],p[n];

    for(i=0;i<n;i++){
        printf("Enter priority of P%d: ",i+1);
        scanf("%d",&pr[i]);
        p[i]=i+1;
    }

    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(pr[i] < pr[j]){
                t=pr[i]; pr[i]=pr[j]; pr[j]=t;
                t=p[i];  p[i]=p[j];   p[j]=t;
            }

    printf("\nExecution order: ");
    for(i=0;i<n;i++) printf("P%d ",p[i]);
}

