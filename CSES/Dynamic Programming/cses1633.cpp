#include <cstdio>

using namespace std;

const int N = 1e6+5, MOD = 1e9+7;

int n;
int dp[N];

int main() {
  scanf("%d", &n);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int k = 1; k <= 6 && (i - k) >= 0; k++) {
      dp[i] = (dp[i] + dp[i-k])%MOD;
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}