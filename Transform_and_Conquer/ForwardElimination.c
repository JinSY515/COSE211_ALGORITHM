#include <stdio.h>

int A[100][101];
int b[100];

void print(int A[][101], int n);
void ForwardElimination(int A[][101], int b[], int n){
    for(int i=1; i<=n; i++){
        A[i][n+1]= b[i];
    }

    for(int i=1; i<=n-1; i++){
        for(int j=i+1; j<=n; j++){
            float tmp= (float)(A[j][i]/A[i][i]);
            for(int k=i; k<=(n+1); k++){
                
                A[j][k] = A[j][k] - A[i][k] *tmp;
                print(A, n);
                printf("\n");
            }
        }
    }
}

void print(int A[][101], int n){
  for(int i=1; i<=n; i++){
        for(int j=1; j<=n+1; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &A[i][j]);
        }
    }

    for(int i=1; i<=n; i++){
      scanf("%d", &b[i]);
    }
    ForwardElimination(A, b, n);

    print(A, n);
    return 0;
}