#include <stdio.h>

int A[100];
int S[100];
int Count[100];

void ComparisonCountingSort(int *A, int n){
    for(int i=0; i<n; i++){
        Count[i]=0;
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(A[i]<A[j]){
                Count[j]++;
            }
            else Count[i]++;
        }
    }

    for(int i=0; i<n; i++){
        S[Count[i]]=A[i];
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    ComparisonCountingSort(A,n);
    printf("After sorting by Comparison Counting Sort\n");
    for(int i=0; i<n; i++){
        printf("%d ", S[i]);
    }
    return 0;
}