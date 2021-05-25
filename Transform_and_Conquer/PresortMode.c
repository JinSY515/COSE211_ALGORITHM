#include <stdio.h>
#include <stdlib.h>

int a[100];

int cmp(const void *a, const void*b){
    int n1 = *(int *)a;
    int n2 = *(int *)b;

    if(n1 < n2) return -1;
    else if( n1> n2) return 1;
    else return 0;
}
int PresortMode(int a[], int n){
    qsort(a, n, sizeof(int), cmp); // sort O(nlogn)
    for(int i=0; i<n; i++){
      printf("%d ", a[i]);
    }
    printf("\n");
    int modelen = 0;
    int modeval =0;
    int i=0;
    int len, val;
    while(i<n){    //Stage2 :O(n) : linear
        len = 1;
        val = a[i];
        while( i +len < n && a[i+len] == val){
            len++;
        }
        if(len > modelen){
            modelen= len;
           modeval = val;
         }
       i = i+len;
        
    }
    return modeval;
}
int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int mode = PresortMode(a, n);
    printf("%d", mode);
    return 0;

    //Tsort(n) + Tscan(n) = T(n)
    //O(nlogn) + O(n) = O(nlogn)
}