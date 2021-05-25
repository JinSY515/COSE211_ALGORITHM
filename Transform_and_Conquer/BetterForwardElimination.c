#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float A[100][101];
int b[100];

void print(float A[][101], int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n+1; j++){
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }
}



void BetterForwardElimination(float A[][101], int b[], int n){
    for(int i=1; i<=n; i++){
        A[i][n+1] = b[i];
    }

    for(int i=1; i<=n-1; i++){
        int pivotRow = i;
        for(int j=i+1; j<=n; j++){
            if(fabsf(A[j][i])> fabsf(A[pivotRow][i])) pivotRow = j;
        }

        for(int k=i; k<=n+1; k++){
            //swap
            int tmp=A[i][k];
            A[i][k]=A[pivotRow][k];
            A[pivotRow][k]=tmp;
        }

        for(int j=i+1; j<=n; j++){
            float temp = A[j][i]/A[i][i];
            for(int k=i; k<=n+1; k++){
                A[j][k]=A[j][k]-A[i][k]*temp;
                print(A, n);
                printf("\n");
            }
            
        }
    }
}


int main(void){
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%f", &A[i][j]);
        }
    }

    for(int i=1; i<=n; i++){
        scanf("%d", &b[i]);
    }

    BetterForwardElimination(A,b,n);
    print(A,n);
    return 0;
}