#include <stdio.h>

int A[100];
int S[100];
int D[100];

void DistributionCountingSort(int *A, int l, int u, int n){
    for(int i=0; i<=u-l; i++){
        D[i]=0;
    }
    for(int i=0; i<n; i++){
        D[A[i]-l]++;
    }
    for(int i=1; i<=u-l; i++){
        D[i] = D[i-1]+D[i];
    }

    for(int i=n-1; i>=0; i--){
        int j = A[i]-l;
        S[D[j]-1] = A[i];
        D[j]--;
    }
}

int min(int a, int b){
    if(a<b) return a;
    else return b;
}

int max(int a, int b){
    if(a>b) return a;
    else return b;
}
int main(void){
    int n;
    scanf("%d", &n);

    int m=987654321;
    int M=-987654321;
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
        m=min(m, A[i]);
        M=max(M, A[i]);
    }

    DistributionCountingSort(A, m, M, n);

    for(int i=0; i<n; i++){
        printf("%d ", S[i]);
    }
    return 0;
}