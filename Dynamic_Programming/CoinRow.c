#include <stdio.h>

int c[100];
int F[100];

int max(int a, int b){
  if(a>b) return a;
  else return b;
}
void CoinRow(int c[], int n){
    F[0]=0;
    F[1]=c[1];

    for(int i=2; i<=n; i++){
        F[i]=max(F[i-1], F[i-2]+c[i]);
    }
}
int main(void){
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &c[i]);
    }

    CoinRow(c, n);
    printf("%d is the highest\n", F[n]);

    return 0;

}