#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e6 + 5, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, cln, d;
int dp[N];

int main() {
  scanf("%d", &n);
  fill(dp, dp+10, 1);
  for (int rem = 10; rem <= n; rem++) {
    cln = rem;
    dp[rem] = OO;
    while (cln) {
      d = cln % 10;
      cln /= 10;
      dp[rem] = min(dp[rem], dp[rem - d] + 1);
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}