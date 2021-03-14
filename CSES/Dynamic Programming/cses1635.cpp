#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e2+5, M = 1e6+5, OO = 0x3f3f3f3f, MOD = 1e9+7;

int n, x;
int A[N], dp[M];

int main() {
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; i++) {
    scanf("%d", A+i);
  }
  dp[0] = 1;
  for (int i = 1; i <= x; i++) {
    for (int k = 0; k < n; k++) {
      if (i >= A[k]) {
        dp[i] = (dp[i] + dp[i - A[k]]) % MOD;
      }
    }
  }
  printf("%d\n", dp[x]);
  return 0;
}