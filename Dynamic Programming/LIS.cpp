#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 1e3 + 2, M = 1e4+5, OO = 0x3f3f3f3f;

int n, A[N];
int mem[N][N];

int solve(int i = 0, int prev = n){     //Memory -> O(n^2), Time -> O(n^2)
  if(i == n)  return 0;
  int& ret = mem[i][prev];
  if(~ret)  return ret;
  return ret = max(solve(i+1, prev), (A[i]>A[prev]? solve(i+1, i)+1 : 0));
}

int main(){
  scanf("%d", &n);
  for(int i = 0 ; i < n ; ++i)  scanf("%d", A+i);
  memset(mem, -1, sizeof mem);
  printf("%d\n", solve());
  return 0;
}
