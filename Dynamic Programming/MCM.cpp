#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 1e2 + 5, M = 1e3+5, OO = 0x3f3f3f3f, mod = 1e9+7;

int n, R[N], C[N];

ll mem[N][N];
ll solve(int i = 0, int j = n-1){
  if(i == j)  return 0;
  ll& ret = mem[i][j];
  if(~ret)  return ret;
  ret = OO*1ll*OO;
  for(int m = i ; m < j ; ++m)
    ret = min(ret, solve(i, m)+solve(m+1, j)+R[i]*C[j]*C[m]);
  return ret;
}

int main(){
  scanf("%d", &n);
  for(int i = 0 ; i < n ; ++i)  scanf("%d %d", R+i, C+i);
  memset(mem, -1, sizeof mem);
  solve();
  return 0;
}
