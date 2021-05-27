#include <stdio.h>
#include <string.h>

char P[100];
char T[1000];

int Table[27];

void ShiftTable(char P[], int m){
    for(int i=0; i<27; i++){
        Table[i]=m;
    }
    for(int i=0; i<m-1; i++){
        int ch = (int)(P[i])-65;
        if(0<=ch &&ch <=26)
        Table[ch] = m-1-i;
    }
}

int Horspool(char P[], char T[], int m, int n, int Table[]){
  
  int i=m-1;
  int k;
  while(i<n){
    k=0;
    while(k<m && P[m-1-k]==T[i-k]){
      k++;
    }
    if(k==m) return i-m+1;
    else{
      int ch = (int)(T[i])-65;
      if(0<=ch && ch <=26)
      i=i+Table[ch];
      else i+=m;
    }
    
  }

  return -1;
}
int main(void){
  scanf("%[^\n]", T);
  int m;
  int n;
  scanf("%s", P);
  
  n=strlen(T);
  m=strlen(P);
  ShiftTable(P, m);
  int ret = Horspool(P,T,m,n,Table);
  if(ret==-1) printf("We couldn't find the pattern in the text\n");
  else
  printf("At index %d we found the pattern!\n",ret);
  return 0;
}
