#include <stdio.h>

int D[100];
int F[100];

int min(int a, int b){
  if(a<b) return a;
  else return b;
}
void ChangeMaking(int D[], int m, int n){
    F[0]=0;

    for(int i=1; i<=n; i++){
        int tmp = 987654321;
        int j=1;

        while(j<=m && i>=D[j]){
            tmp = min(F[i-D[j]], tmp);
            j++;
        }
        F[i]=tmp+1;
    }
}
int main(void){
    int n;
    int m;
    scanf("%d %d", &m, &n);
    for(int i=1; i<=m; i++){
        scanf("%d", &D[i]);
    }

    ChangeMaking(D, m, n);

    for(int i=1; i<=n; i++){
        printf("%d ", F[i]);
    }
    return 0;
}