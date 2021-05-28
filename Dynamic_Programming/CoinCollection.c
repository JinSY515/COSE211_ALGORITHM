#include <stdio.h>

int C[100][100];
int F[100][100];

int max(int a, int b){
    if(a>b) return a;
    else return b;
}
void CoinCollection(int C[][100], int n, int m){
    F[1][1]=C[1][1];
    for(int j=2; j<=m; j++) F[1][j] = F[1][j-1]+C[1][j];
    for(int i=2; i<=n; i++) {
        F[i][1] = F[i-1][1]+C[i][1];
        for(int j=2; j<=m; j++){
            F[i][j]=max(F[i-1][j], F[i][j-1])+C[i][j];
        }
    }
}
int main(void){
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &C[i][j]);
        }
    }

    CoinCollection(C, n, m);
    for(int i=1; i<=n; i++){
        for(int j=1 ; j<=m; j++){
            printf("%d ", F[i][j]);
        }
        printf("\n");
    }

    printf("The largest number that the robot can collect is %d\n", F[n][m]);
    return 0;

}