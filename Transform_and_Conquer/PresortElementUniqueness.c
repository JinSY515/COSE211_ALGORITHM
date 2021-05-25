#include <stdio.h>
#include <stdlib.h>

int a[100];
int cmp(const void *a, const void *b)   
{
    int num1 = *(int *)a;   
    int num2 = *(int *)b;  

    if (num1 < num2)
        return -1;     
    
    if (num1 > num2)   
        return 1;       
    
    return 0;   
}

int PresortElementUniqueness(int a[], int n){
    qsort(a, n, sizeof(int), cmp);  //O(nlogn)
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    for(int i=0; i<n-1; i++){
      if(a[i]==a[i+1]) return 1;   //O(n)
    }
    return 0;
}
int main(void){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    if(PresortElementUniqueness(a, n)) printf("Unique");
    else printf("Not Unique");

    return 0;

    //Tsort(n) + Tscan(n) = T(n)
    //O(nlogn) + O(n) = O(nlogn) 
}