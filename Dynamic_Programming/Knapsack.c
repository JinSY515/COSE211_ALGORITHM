#include <stdio.h>

int F[100][100];
int WV[100][2];

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

void Knapsack(int WV[][2], int n, int w){
    for(int j=0; j<=w; j++) F[0][j]=0;
    for(int i=0; i<=n; i++) F[i][0]=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(j>=WV[i][0]){
                F[i][j] = max(F[i-1][j], WV[i][1]+F[i-1][j-WV[i][0]]);
            }
            else 
                F[i][j] = F[i-1][j];
        }
    } 
}
int main(void){
    int n,w;
    scanf("%d", &n);
    printf("capacity: ");
    scanf("%d", &w);

    for(int i=1; i<=n; i++){
      for(int j=0; j<=1; j++){
        scanf("%d", &WV[i][j]);
      }
    }

    Knapsack(WV, n, w);

    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            printf("%3d ", F[i][j]);
        }
        printf("\n");
    }
    return 0;
}