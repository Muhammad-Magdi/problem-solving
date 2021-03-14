#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e2+5, M = 1e6+5, OO = 0x3f3f3f3f;

int n, x;
int A[N], dp[M];

int main() {
  scanf("%d %d", &n, &x);
  memset(dp, OO, sizeof dp);
  for (int i = 0; i < n; i++) {
    scanf("%d", A+i);
  }
  dp[0] = 0;
  for (int i = 1; i <= x; i++) {
    for (int k = 0; k < n; k++) {
      if (i >= A[k]) {
        dp[i] = min(dp[i], dp[i-A[k]] + 1);
      }
    }
  }
  printf("%d\n", dp[x] == OO ? -1 : dp[x]);
  return 0;
}