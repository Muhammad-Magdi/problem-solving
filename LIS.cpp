/*
  Different Solutions for LIS Problem
  Muhammad Magdi
*/
#include <bits/stdc++.h>

using namespace std;
const int N = 1000, M = 2e6, OO = 1000000007, EPS = 0.00000001;

int n , A[N+9], mem[N+9][N+9];

int LIS(int i = 0, int prev = n){     //Memory -> O(n^2), Time -> O(n^2)
  if(i == n)  return 0;
  int &ret = mem[i][prev];
  if(~ret)  return ret;
  return ret = max(LIS(i+1, prev), (A[i]>A[prev]? LIS(i+1, i)+1 : 0));
}

int dp[N+9][N+9];
int iterativeLIS(){    //Memory -> O(n^2), Time -> O(n^2)
  for(int i = 0 ; i <= n ; ++i)
    dp[n][i] = 0;
  for(int i = n-1 ; ~i ; --i)
    for(int prev = n ; ~prev ; --prev)
      dp[i][prev] = max(dp[i+1][prev], ((prev == n || A[i]>A[prev])? dp[i+1][i]+1 : 0));
  return dp[0][n];
}

int rdp[2][N+9];
int rollingLIS(){    //Memory -> O(n), Time -> O(n^2)
  int r = 0;
  for(int i = 0 ; i <= n ; ++i)     //Base Case
    rdp[r][i] = rdp[!r][i] = 0;
  for(int i = n-1 ; ~i ; --i){      //Bottom-Up Approach
    r = !r;                         //switch to the other row
    for(int prev = n ; ~prev ; --prev)
      rdp[r][prev] = max(rdp[!r][prev], ((prev == n || A[i]>A[prev])? rdp[r][i]+1 : 0));
  }
  return rdp[r][n];
}

int greadyLIS(){    //Memory -> O(n), Time -> O(nLogn)
  vector<int> ret;
  for(int i=0; i<n; i++){
    auto it = lower_bound(ret.begin(), ret.end(), A[i]);
    if(it == ret.end()) ret.push_back(A[i]);
    else *it = A[i];
  }
  return (int)ret.size();
}

int main(){
	// freopen("i.in", "r", stdin);
	// freopen("o.out", "w", stdout);
  memset(mem, -1, sizeof mem);
  scanf("%d", &n);
  for(int i = 0 ; i < n ; ++i)
    scanf("%d", A+i);
  printf("%d\n%d\n%d\n%d\n", LIS(), iterativeLIS(), rollingLIS(), greadyLIS());
  return 0;
}

/* input sample
3
1 4 2 4 3
*/
