#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e3 + 5, M = 1e5 + 2, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, x;
int H[N], S[N];

int dp[2][M]; // availableBooks, remainingMoney

int solve() {
  fill(dp[0], dp[0] + x + 1, 0);
  dp[0][0] = dp[1][0] = 0;

  for (int availableBooks = 1; availableBooks <= n; availableBooks++) {
    dp[availableBooks & 1][0] = 0;
    for (int remainingMoney = 1; remainingMoney <= x; remainingMoney++) {
      dp[availableBooks & 1][remainingMoney] =
          dp[(availableBooks - 1) & 1][remainingMoney];
      if (remainingMoney >= H[availableBooks]) {
        dp[availableBooks & 1][remainingMoney] =
            max(dp[availableBooks & 1][remainingMoney],
                dp[(availableBooks - 1) & 1][remainingMoney - H[availableBooks]] + S[availableBooks]);
      }
    }
  }
  return dp[n&1][x];
}

int main() {
  scanf("%d %d", &n, &x);
  for (int i = 1; i <= n; i++) {
    scanf("%d", H + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", S + i);
  }
  printf("%d\n", solve());
  return 0;
}