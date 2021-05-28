#include <stdio.h>

int D[100][100];

void Warshall(int D[][100], int n){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(!D[i][j]){
                    if(D[i][k] && D[k][j]) D[i][j]=1;
                }
            }
        }
    }
}
int main(void){
    int n;
    printf("vertices #: ");
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        for(int j=1;j<=n; j++){
            scanf("%d",&D[i][j]);
        }
    }
    Warshall(D, n);
    printf("\nTransitive Closure\n");
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }
    return 0;
}