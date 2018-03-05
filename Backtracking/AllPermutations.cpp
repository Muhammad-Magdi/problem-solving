#include <bits/stdc++.h>

using namespace std;
const int N = 1e2 +5 , M = 1e4 +5, OO = 1000000007;

int n, A[N], permutation[N], sitted[N];

void solveAP(int idx = 0){
  if(idx == n){
    for(int i = 0 ; i < n ; ++i)
      printf("%d ", permutation[i]);
    puts("");
    return;
  }
  for(int i = 0 ; i < n ; ++i){
    if(!sitted[i]){
      sitted[i] = 1;
      permutation[idx] = A[i];
      solveAP(idx+1);
      sitted[i] = 0;
    }
  }
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
  scanf("%d", &n);
  for(int i = 0 ; i < n ; ++i)
    scanf("%d", A+i);
  solveAP();
  return 0;
}









/*
*/
