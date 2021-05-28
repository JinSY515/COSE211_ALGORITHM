#include <stdio.h>

int Weight[100];
int Value[100];

int F[100][100];
int max(int a, int b){
    if(a>b) return a;
    else return b;
}

void Init(int n, int w){
    for(int i=0; i<=n; i++){
      for(int j=0; j<=w; j++) F[i][j]=-1;
    }
    F[0][0]=0;
    for(int j=1; j<=w; j++) F[0][j]=0;
    for(int i=1; i<=n; i++) F[i][0]=0;
}
int MemoryKnapsack(int i, int j){
    int value;
    if(F[i][j]<0){ //Not visited
        if(j<Weight[i]){
            value=MemoryKnapsack(i-1, j);
        }
        else{
            value = max(MemoryKnapsack(i-1,j), Value[i]+MemoryKnapsack(i-1, j-Weight[i]));
        }
        F[i][j]=value;
    }
    return F[i][j];
}

int main(void){

    int n;
    printf("items #: ");
    scanf("%d", &n);
    int w;
    printf("capacity: ");
    scanf("%d", &w);
    for(int i=1; i<=n; i++){
      printf("(w,v) %d: ",i);
        scanf("%d%d", &Weight[i], &Value[i]);
    }
    Init(n,w);
    MemoryKnapsack(n,w);

    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(F[i][j]<0) printf(" - ");
            else printf("%3d", F[i][j]);
        }
        printf("\n");
    }

    return 0;

}
