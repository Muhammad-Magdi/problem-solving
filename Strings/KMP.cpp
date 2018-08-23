//SPOJ EPALIN

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int N = 1e5+5, M = 2e5+5, OO = 0x3f3f3f3f;

int n;
char str[N], pat[M];
int F[M];

int getNextLen(int len, char c){
  while(len && pat[len] != c)
    len = F[len-1];
  if(pat[len] == c) ++len;
  return len;
}

void computeF(){
  F[0] = 0;
  for(int i = 1 ; i < n ; ++i)
    F[i] = getNextLen(F[i-1], pat[i]);
}

int main(){
  while(~scanf("%s", str)){
    strcpy(pat, str);
    reverse(pat, pat+strlen(pat));
    strcat(pat, "#");
    strcat(pat, str);       //pat = reversedString + # + givenString
    n = strlen(pat);
    computeF();
    printf("%s", str);
    for(int i = strlen(str)-1-F[n-1] ; ~i ; --i)  printf("%c", str[i]);
    puts("");
  }
  return 0;
}
